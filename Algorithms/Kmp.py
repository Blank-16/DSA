def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    
    if m == 0:
        return 0
    
    lps = build_lps(pattern)
    
    i = 0  # pointer for text
    j = 0  # pointer for pattern
    
    while i < n:
        
        if text[i] == pattern[j]:
            i += 1
            j += 1
        
        if j == m:
            # full match found
            return i - j
        
        elif i < n and text[i] != pattern[j]:
            if j != 0:
                # jump using LPS instead of restarting
                j = lps[j - 1]
            else:
                i += 1
    
    return -1
