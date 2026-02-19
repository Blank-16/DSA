def rabin_karp(text, pattern):
    n = len(text)
    m = len(pattern)
    
    if m > n:
        return -1
    
    base = 256          # number of possible characters (ASCII)
    mod = 10**9 + 7     # large prime to avoid overflow
    
    pattern_hash = 0
    window_hash = 0
    power = 1           # base^(m-1) % mod
    
    # Precompute base^(m-1)
    for _ in range(m - 1):
        power = (power * base) % mod
    
    # Compute initial hashes for pattern and first window
    for i in range(m):
        pattern_hash = (pattern_hash * base + ord(pattern[i])) % mod
        window_hash = (window_hash * base + ord(text[i])) % mod
    
    # Slide over text
    for i in range(n - m + 1):
        
        # If hashes match, verify characters (avoid collision issue)
        if pattern_hash == window_hash:
            if text[i:i+m] == pattern:
                return i
        
        # Compute next window hash
        if i < n - m:
            # Remove leading character
            window_hash = (window_hash - ord(text[i]) * power) % mod
            
            # Shift hash and add new character
            window_hash = (window_hash * base + ord(text[i + m])) % mod
            
            # Ensure positive hash
            window_hash = (window_hash + mod) % mod
    
    return -1
