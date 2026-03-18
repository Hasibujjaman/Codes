# encryption, decryption and menu functions for Caesar cipher

def encrypt(text, k):
    cipher_text = ""
    for char in text:
        if char >= 'A' and char <= 'Z':
            cipher_text += chr((ord(char) + k - ord('A')) % 26 + ord('A'))
        elif char >= 'a' and char <= 'z':
            cipher_text += chr((ord(char) + k - ord('a')) % 26 + ord('a'))
        else:
            cipher_text += char
    return cipher_text

def decrypt(text, k):
    plain_text = ""
    for char in text:
        if char >= 'A' and char <= 'Z':
            plain_text += chr((ord(char) - k - ord('A')) % 26 + ord('A'))
        elif char >= 'a' and char <= 'z':
            plain_text += chr((ord(char) - k - ord('a')) % 26 + ord('a'))
        else:
            plain_text += char
    return plain_text


def brute_force_attack(cipher_text):
    for k in range(1, 26):
        plain_text = decrypt(cipher_text, k)
        print(f"Shift {k}: {plain_text}")

def caesar_menu():
    while True:
        print("\nCaesar Cipher Menu")
        print("1. Encrypt")
        print("2. Decrypt")
        print("3. Brute Force Attack")
        print("4. Exit")
        choice = input("Enter your choice (1-4): ")

        if choice == '1':
            input_text = input("Enter text to encrypt: ")
            k = int(input("Enter shift value (1-25): "))
            cipher_text = encrypt(input_text, k)
            print("Cipher Text: ", cipher_text)

        elif choice == '2':
            input_text = input("Enter text to decrypt: ")
            k = int(input("Enter shift value (1-25): "))
            plain_text = decrypt(input_text, k)
            print("Plain Text: ", plain_text)

        elif choice == '3':
            cipher_text = input("Enter cipher text for brute force attack: ")
            brute_force_attack(cipher_text)
            break

        elif choice == '4':
            break

        else:
            print("Invalid. Try again.")
        
caesar_menu()