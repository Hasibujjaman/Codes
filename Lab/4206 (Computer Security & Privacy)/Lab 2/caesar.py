#Casar Cipher

input_text = input("Enter text to encrypt: ")
k = int(input("Enter shift value (1-25): "))
cipher_text = ""

for char in input_text:
    if char >= 'A' and char <= 'Z':
        cipher_text += chr((ord(char) + k - ord('A')) % 26 + ord('A'))
    elif char >= 'a' and char <= 'z':
        cipher_text += chr((ord(char) + k - ord('a')) % 26 + ord('a'))
    else:
        cipher_text += char
print("Cipher Text: ", cipher_text)