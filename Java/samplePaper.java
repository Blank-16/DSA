
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class samplePaper {

    private static Path currentDirectory = Paths.get(System.getProperty("user.dir"));
    private static final Scanner scanner = new Scanner(System.in);
    private static final List<String> commandHistory = new ArrayList<>();
    private static final Map<String, String> environmentVariables = new HashMap<>();

    public static void main(String[] args) {
        initializeEnvironment();
        printWelcomeMessage();

        while (true) {
            try {
                String prompt = getCurrentPrompt();
                System.out.print(prompt);

                String input = scanner.nextLine().trim();

                if (input.isEmpty()) {
                    continue;
                }

                commandHistory.add(input);

                if (input.equalsIgnoreCase("exit") || input.equalsIgnoreCase("quit")) {
                    System.out.println("Goodbye!");
                    break;
                }

                executeCommand(input);

            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close();
    }

    private static void initializeEnvironment() {
        environmentVariables.put("USER", System.getProperty("user.name"));
        environmentVariables.put("HOME", System.getProperty("user.home"));
        environmentVariables.put("OS", System.getProperty("os.name"));
        environmentVariables.put("JAVA_VERSION", System.getProperty("java.version"));
    }

    private static void printWelcomeMessage() {
        System.out.println("╔══════════════════════════════════════╗");
        System.out.println("║      Java Terminal v1.0              ║");
        System.out.println("║      Type 'help' for commands        ║");
        System.out.println("║      Type 'exit' to quit             ║");
        System.out.println("╚══════════════════════════════════════╝");
        System.out.println();
    }

    private static String getCurrentPrompt() {
        String user = environmentVariables.get("USER");
        String dirName = currentDirectory.getFileName() != null
                ? currentDirectory.getFileName().toString()
                : currentDirectory.toString();
        return String.format("[%s@JavaTerminal %s]$ ", user, dirName);
    }

    private static void executeCommand(String input) {
        String[] parts = input.split("\\s+");
        String command = parts[0].toLowerCase();
        String[] args = Arrays.copyOfRange(parts, 1, parts.length);

        switch (command) {
            case "help" -> showHelp();
            case "ls", "dir" -> listDirectory(args);
            case "cd" -> changeDirectory(args);
            case "pwd" -> System.out.println(currentDirectory.toAbsolutePath());
            case "mkdir" -> makeDirectory(args);
            case "rmdir" -> removeDirectory(args);
            case "touch", "create" -> createFile(args);
            case "rm", "del" -> deleteFile(args);
            case "cat", "type" -> displayFile(args);
            case "echo" -> echo(args);
            case "clear", "cls" -> clearScreen();
            case "history" -> showHistory();
            case "env" -> showEnvironment();
            case "set" -> setEnvironmentVariable(args);
            case "date" -> showDate();
            case "time" -> showTime();
            case "whoami" -> System.out.println(environmentVariables.get("USER"));
            case "tree" -> showTree(args);
            case "find" -> findFiles(args);
            case "grep" -> grepInFiles(args);
            case "wc" -> wordCount(args);
            case "cp", "copy" -> copyFile(args);
            case "mv", "move" -> moveFile(args);
            case "chmod" -> changePermissions(args);
            case "ps" -> showProcesses();
            case "java" -> runJavaCommand(args);
            case "compile" -> compileJava(args);
            case "run" -> runJavaClass(args);
            default -> {
                System.out.println("Command not found: " + command);
                System.out.println("Type 'help' for available commands.");
            }
        }
    }

    private static void showHelp() {
        System.out.println("Available Commands:");
        System.out.println("==================");
        System.out.println("File & Directory Operations:");
        System.out.println("  ls/dir [path]      - List directory contents");
        System.out.println("  cd <path>          - Change directory");
        System.out.println("  pwd                - Print working directory");
        System.out.println("  mkdir <name>       - Create directory");
        System.out.println("  rmdir <name>       - Remove directory");
        System.out.println("  touch/create <name> - Create file");
        System.out.println("  rm/del <file>      - Delete file");
        System.out.println("  cat/type <file>    - Display file contents");
        System.out.println("  cp/copy <src> <dst> - Copy file");
        System.out.println("  mv/move <src> <dst> - Move file");
        System.out.println();
        System.out.println("Text Operations:");
        System.out.println("  echo <text>        - Print text");
        System.out.println("  grep <pattern> <file> - Search in file");
        System.out.println("  wc <file>          - Word count");
        System.out.println();
        System.out.println("System Operations:");
        System.out.println("  clear/cls          - Clear screen");
        System.out.println("  history            - Show command history");
        System.out.println("  env                - Show environment variables");
        System.out.println("  set <var> <value>  - Set environment variable");
        System.out.println("  date               - Show current date");
        System.out.println("  time               - Show current time");
        System.out.println("  whoami             - Show current user");
        System.out.println("  ps                 - Show running processes");
        System.out.println();
        System.out.println("Java Operations:");
        System.out.println("  compile <file>     - Compile Java file");
        System.out.println("  run <class>        - Run Java class");
        System.out.println("  java <args>        - Execute java command");
        System.out.println();
        System.out.println("Utility:");
        System.out.println("  tree [path]        - Show directory tree");
        System.out.println("  find <name>        - Find files");
        System.out.println("  exit/quit          - Exit terminal");
    }

    private static void listDirectory(String[] args) {
        try {
            Path targetPath = args.length > 0
                    ? currentDirectory.resolve(args[0])
                    : currentDirectory;

            if (!Files.exists(targetPath)) {
                System.out.println("Directory not found: " + args[0]);
                return;
            }

            if (!Files.isDirectory(targetPath)) {
                System.out.println("Not a directory: " + args[0]);
                return;
            }

            System.out.printf("Contents of %s:\n", targetPath.toAbsolutePath());
            System.out.println("Type\t\tSize\t\tName");
            System.out.println("----\t\t----\t\t----");

            try (DirectoryStream<Path> stream = Files.newDirectoryStream(targetPath)) {
                for (Path entry : stream) {
                    String type = Files.isDirectory(entry) ? "DIR" : "FILE";
                    long size = Files.isDirectory(entry) ? 0 : Files.size(entry);
                    String sizeStr = size > 0 ? String.format("%d bytes", size) : "-";

                    System.out.printf("%-8s\t%-12s\t%s\n",
                            type, sizeStr, entry.getFileName());
                }
            }
        } catch (IOException e) {
            System.out.println("Error listing directory: " + e.getMessage());
        }
    }

    private static void changeDirectory(String[] args) {
        if (args.length == 0) {
            currentDirectory = Paths.get(environmentVariables.get("HOME"));
            return;
        }

        String targetDir = args[0];
        Path newPath;

        switch (targetDir) {
            case ".." -> {
                newPath = currentDirectory.getParent();
                if (newPath == null) {
                    System.out.println("Already at root directory");
                    return;
                }
            }
            case "~" -> newPath = Paths.get(environmentVariables.get("HOME"));
            default -> newPath = currentDirectory.resolve(targetDir);
        }

        if (Files.exists(newPath) && Files.isDirectory(newPath)) {
            currentDirectory = newPath.normalize();
        } else {
            System.out.println("Directory not found: " + targetDir);
        }
    }

    private static void makeDirectory(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: mkdir <directory_name>");
            return;
        }

        try {
            Path newDir = currentDirectory.resolve(args[0]);
            Files.createDirectories(newDir);
            System.out.println("Directory created: " + args[0]);
        } catch (IOException e) {
            System.out.println("Error creating directory: " + e.getMessage());
        }
    }

    private static void removeDirectory(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: rmdir <directory_name>");
            return;
        }

        try {
            Path dirToRemove = currentDirectory.resolve(args[0]);
            if (Files.exists(dirToRemove) && Files.isDirectory(dirToRemove)) {
                Files.delete(dirToRemove);
                System.out.println("Directory removed: " + args[0]);
            } else {
                System.out.println("Directory not found: " + args[0]);
            }
        } catch (IOException e) {
            System.out.println("Error removing directory: " + e.getMessage());
        }
    }

    private static void createFile(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: touch <filename>");
            return;
        }

        try {
            Path newFile = currentDirectory.resolve(args[0]);
            if (!Files.exists(newFile)) {
                Files.createFile(newFile);
                System.out.println("File created: " + args[0]);
            } else {
                // Update timestamp
                Files.setLastModifiedTime(newFile,
                        java.nio.file.attribute.FileTime.fromMillis(System.currentTimeMillis()));
                System.out.println("File timestamp updated: " + args[0]);
            }
        } catch (IOException e) {
            System.out.println("Error creating file: " + e.getMessage());
        }
    }

    private static void deleteFile(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: rm <filename>");
            return;
        }

        try {
            Path fileToDelete = currentDirectory.resolve(args[0]);
            if (Files.exists(fileToDelete)) {
                Files.delete(fileToDelete);
                System.out.println("File deleted: " + args[0]);
            } else {
                System.out.println("File not found: " + args[0]);
            }
        } catch (IOException e) {
            System.out.println("Error deleting file: " + e.getMessage());
        }
    }

    private static void displayFile(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: cat <filename>");
            return;
        }

        try {
            Path file = currentDirectory.resolve(args[0]);
            if (Files.exists(file) && Files.isRegularFile(file)) {
                List<String> lines = Files.readAllLines(file);
                for (String line : lines) {
                    System.out.println(line);
                }
            } else {
                System.out.println("File not found: " + args[0]);
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    private static void echo(String[] args) {
        if (args.length == 0) {
            System.out.println();
            return;
        }

        String output = String.join(" ", args);
        System.out.println(output);
    }

    private static void clearScreen() {
        // Clear screen for different OS
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                System.out.print("\033[2J\033[H");
            }
        } catch (Exception e) {
            // Fallback: print empty lines
            for (int i = 0; i < 50; i++) {
                System.out.println();
            }
        }
    }

    private static void showHistory() {
        System.out.println("Command History:");
        for (int i = 0; i < commandHistory.size(); i++) {
            System.out.printf("%4d  %s\n", i + 1, commandHistory.get(i));
        }
    }

    private static void showEnvironment() {
        System.out.println("Environment Variables:");
        for (Map.Entry<String, String> entry : environmentVariables.entrySet()) {
            System.out.printf("%s=%s\n", entry.getKey(), entry.getValue());
        }
    }

    private static void setEnvironmentVariable(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: set <variable> <value>");
            return;
        }

        String var = args[0];
        String value = String.join(" ", Arrays.copyOfRange(args, 1, args.length));
        environmentVariables.put(var, value);
        System.out.println("Set " + var + "=" + value);
    }

    private static void showDate() {
        System.out.println(new Date());
    }

    private static void showTime() {
        System.out.printf("Current time: %tT\n", new Date());
    }

    private static void showTree(String[] args) {
        Path startPath = args.length > 0
                ? currentDirectory.resolve(args[0])
                : currentDirectory;

        if (!Files.exists(startPath) || !Files.isDirectory(startPath)) {
            System.out.println("Invalid directory path");
            return;
        }

        System.out.println(startPath.toAbsolutePath());
        showTreeRecursive(startPath, "", true);
    }

    private static void showTreeRecursive(Path dir, String prefix, boolean isRoot) {
        try (DirectoryStream<Path> stream = Files.newDirectoryStream(dir)) {
            List<Path> paths = new ArrayList<>();
            stream.forEach(paths::add);
            paths.sort(Comparator.comparing(Path::getFileName));

            for (int i = 0; i < paths.size(); i++) {
                Path path = paths.get(i);
                boolean isLast = (i == paths.size() - 1);

                System.out.println(prefix + (isLast ? "└── " : "├── ") + path.getFileName());

                if (Files.isDirectory(path)) {
                    showTreeRecursive(path, prefix + (isLast ? "    " : "│   "), false);
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading directory: " + e.getMessage());
        }
    }

    private static void findFiles(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: find <filename_pattern>");
            return;
        }

        String pattern = args[0];
        try {
            Files.walk(currentDirectory)
                    .filter(Files::isRegularFile)
                    .filter(path -> path.getFileName().toString().contains(pattern))
                    .forEach(System.out::println);
        } catch (IOException e) {
            System.out.println("Error searching files: " + e.getMessage());
        }
    }

    private static void grepInFiles(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: grep <pattern> <filename>");
            return;
        }

        String pattern = args[0];
        Path file = currentDirectory.resolve(args[1]);

        try {
            if (Files.exists(file) && Files.isRegularFile(file)) {
                List<String> lines = Files.readAllLines(file);
                for (int i = 0; i < lines.size(); i++) {
                    if (lines.get(i).contains(pattern)) {
                        System.out.printf("%d: %s\n", i + 1, lines.get(i));
                    }
                }
            } else {
                System.out.println("File not found: " + args[1]);
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    private static void wordCount(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: wc <filename>");
            return;
        }

        Path file = currentDirectory.resolve(args[0]);

        try {
            if (Files.exists(file) && Files.isRegularFile(file)) {
                List<String> lines = Files.readAllLines(file);
                long lineCount = lines.size();
                long wordCount = lines.stream()
                        .mapToLong(line -> line.split("\\s+").length)
                        .sum();
                long charCount = Files.size(file);

                System.out.printf("Lines: %d, Words: %d, Characters: %d in %s\n",
                        lineCount, wordCount, charCount, args[0]);
            } else {
                System.out.println("File not found: " + args[0]);
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    private static void copyFile(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: cp <source> <destination>");
            return;
        }

        try {
            Path source = currentDirectory.resolve(args[0]);
            Path destination = currentDirectory.resolve(args[1]);

            if (Files.exists(source)) {
                Files.copy(source, destination, StandardCopyOption.REPLACE_EXISTING);
                System.out.println("File copied successfully");
            } else {
                System.out.println("Source file not found: " + args[0]);
            }
        } catch (IOException e) {
            System.out.println("Error copying file: " + e.getMessage());
        }
    }

    private static void moveFile(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: mv <source> <destination>");
            return;
        }

        try {
            Path source = currentDirectory.resolve(args[0]);
            Path destination = currentDirectory.resolve(args[1]);

            if (Files.exists(source)) {
                Files.move(source, destination, StandardCopyOption.REPLACE_EXISTING);
                System.out.println("File moved successfully");
            } else {
                System.out.println("Source file not found: " + args[0]);
            }
        } catch (IOException e) {
            System.out.println("Error moving file: " + e.getMessage());
        }
    }

    private static void changePermissions(String[] args) {
        System.out.println("chmod: File permissions management not fully supported in Java");
        System.out.println("Use your system's native chmod command for full functionality");
    }

    private static void showProcesses() {
        System.out.println("Running Java Processes:");
        System.out.println("PID\t\tName");
        System.out.println("---\t\t----");

        // Show current Java process
        String processName = java.lang.management.ManagementFactory.getRuntimeMXBean().getName();
        System.out.println(processName + "\t\tJavaTerminal");

        // Note: Full process listing requires platform-specific code
        System.out.println("(Limited to current Java process - use system 'ps' for full list)");
    }

    private static void runJavaCommand(String[] args) {
        try {
            List<String> command = new ArrayList<>();
            command.add("java");
            command.addAll(Arrays.asList(args));

            ProcessBuilder pb = new ProcessBuilder(command);
            pb.directory(currentDirectory.toFile());
            pb.inheritIO();

            Process process = pb.start();
            int exitCode = process.waitFor();

            if (exitCode != 0) {
                System.out.println("Java command exited with code: " + exitCode);
            }
        } catch (IOException | InterruptedException e) {
            System.out.println("Error running Java command: " + e.getMessage());
        }
    }

    private static void compileJava(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: compile <filename.java>");
            return;
        }

        try {
            String filename = args[0];
            if (!filename.endsWith(".java")) {
                filename += ".java";
            }

            ProcessBuilder pb = new ProcessBuilder("javac", filename);
            pb.directory(currentDirectory.toFile());
            pb.inheritIO();

            Process process = pb.start();
            int exitCode = process.waitFor();

            if (exitCode == 0) {
                System.out.println("Compilation successful");
            } else {
                System.out.println("Compilation failed with exit code: " + exitCode);
            }
        } catch (IOException | InterruptedException e) {
            System.out.println("Error compiling: " + e.getMessage());
        }
    }

    private static void runJavaClass(String[] args) {
        if (args.length == 0) {
            System.out.println("Usage: run <ClassName>");
            return;
        }

        try {
            String className = args[0];
            if (className.endsWith(".class")) {
                className = className.substring(0, className.length() - 6);
            }

            List<String> command = new ArrayList<>();
            command.add("java");
            command.add(className);

            // Add additional arguments if provided
            if (args.length > 1) {
                command.addAll(Arrays.asList(Arrays.copyOfRange(args, 1, args.length)));
            }

            ProcessBuilder pb = new ProcessBuilder(command);
            pb.directory(currentDirectory.toFile());
            pb.inheritIO();

            Process process = pb.start();
            int exitCode = process.waitFor();

            if (exitCode != 0) {
                System.out.println("Program exited with code: " + exitCode);
            }
        } catch (IOException | InterruptedException e) {
            System.out.println("Error running class: " + e.getMessage());
        }
    }
}
