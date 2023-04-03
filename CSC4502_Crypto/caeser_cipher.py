# AUTHOR: Chew Zi Qing

# textbook 3.32
# question Write a program that can encrypt and decrypt using the general Caesar cipher, also known as an additive cipher.
# key as input
# present the program in class by using 5 data to be encrypted or decrypted.

import sys
import random

'''
"The quick brown fox jumps over the lazy dog", "Gur dhvpx oebja sbk whzcf bire gur ynml qbt"
"A penny saved is a penny earned", "N craar fnirq vf n craar raqvaqned"
"The early bird catches the worm", "Gur rneyl oveq pbagnvaf gur jbez"
"Practice makes perfect", "Cenpgvpr znxrf cersrengvba"
"To be or not to be, that is the question", "Gb or be abg gb or, gung vf gur dhrfgvba"
'''
class DefaultValue:
    def __init__(self, n):
        self.n = n
        self.random_keys = [random.randint(0, 25) for i in range(self.n)]
        self.random_cipher = [
            "Gur dhvpx oebja sbk whzcf bire gur ynml qbt",
            "N craar fnirq vf n craar raqvaqned",
            "Gur rneyl oveq pbagnvaf gur jbez",
            "Cenpgvpr znxrf cersrengvba",
            "Gb or be abg gb or, gung vf gur dhrfgvba"
        ]
        self.random_plain = [
            "The quick brown fox jumps over the lazy dog",
            "A penny saved is a penny earned",
            "The early bird catches the worm",
            "Practice makes perfect",
            "To be or not to be, that is the question",
        ]


class CaesarCipher:
    # plain text: small letter
    # cipher text: capital letter
    alphabets = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
                 ]

    def __init__(self):
        pass

    # C = E(K, p) = (p+K) mod 26
    def encrypt(self, K, p):
        plain_text = list(p)
        cipher_arr = []
        for item in plain_text:
            if item == ' ':
                cipher_arr.append(item)
            else:
                current_idx = self.alphabets.index(item)
                shifted_idx = (current_idx + K) % 26
                cipher_arr.append((self.alphabets[shifted_idx].upper()))
        return "".join(cipher_arr)

    # p = D(k, C) = (C-K) mod 26
    def decrypt(self, k, C):
        cipher_text = list(C)
        plain_arr = []
        for item in cipher_text:
            if item == ' ':
                plain_arr.append(item)
            else:
                current_idx = self.alphabets.index(item.lower())
                shifted_idx = (current_idx - k) % 26
                plain_arr.append((self.alphabets[shifted_idx]))
        return "".join(plain_arr)

    def is_valid_key(self, key):
        return 0 <= key <= 25

    def get_input(self, operation):
        inputs = []
        if operation == 1:
            input_text_type = 'plain'
        else:
            input_text_type = 'cipher'
        inputs.append(input('Enter {} text: '.format(input_text_type)).lower())
        inputs.append(int(input('Enter key (between 0 to 25): ')))
        if not self.is_valid_key(inputs[1]):
            print('Key must be between 0 to 25! Try again')
            sys.exit(1)
        return inputs


if __name__ == '__main__':
    test_caesar = CaesarCipher()

    option = int(input('Encryption (1) or Decryption (2)? '))
    if option == 1:
        [input_plain_text, input_key] = test_caesar.get_input(1)
        print('Cipher text is', test_caesar.encrypt(input_key, input_plain_text))
    elif option == 2:
        [input_cipher_text, input_key] = test_caesar.get_input(2)
        print('Plain text: ', test_caesar.decrypt(input_key, input_cipher_text))
    else:
        print('Invalid Input! Try again.')