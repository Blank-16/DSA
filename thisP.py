import tkinter as tk
from tkinter import ttk

class Calculator:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Calculator")
        self.window.geometry("300x400")
        
        # Entry field for displaying numbers
        self.display = ttk.Entry(self.window, justify="right", font=("Arial", 20))
        self.display.grid(row=0, column=0, columnspan=4, padx=5, pady=5, sticky="nsew")
        
        # Button layout
        buttons = [
            '7', '8', '9', '/',
            '4', '5', '6', '*',
            '1', '2', '3', '-',
            '0', '.', '=', '+'
        ]
        
        # Create and place buttons
        row = 1
        col = 0
        for button in buttons:
            cmd = lambda x=button: self.click(x)
            ttk.Button(self.window, text=button, command=cmd).grid(
                row=row, column=col, padx=2, pady=2, sticky="nsew"
            )
            col += 1
            if col > 3:
                col = 0
                row += 1
        
        # Clear button
        ttk.Button(self.window, text="C", command=self.clear).grid(
            row=row, column=col, padx=2, pady=2, sticky="nsew"
        )
        
        # Configure grid weights
        for i in range(5):
            self.window.grid_rowconfigure(i, weight=1)
        for i in range(4):
            self.window.grid_columnconfigure(i, weight=1)
            
    def click(self, key):
        if key == '=':
            try:
                result = eval(self.display.get())
                self.display.delete(0, tk.END)
                self.display.insert(tk.END, str(result))
            except:
                self.display.delete(0, tk.END)
                self.display.insert(tk.END, "Error")
        else:
            self.display.insert(tk.END, key)
            
    def clear(self):
        self.display.delete(0, tk.END)
        
    def run(self):
        self.window.mainloop()

if __name__ == "__main__":
    calc = Calculator()
    calc.run()

    
