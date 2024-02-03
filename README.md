# SafeKeyMaker

SafeKeyMaker is a simple command-line tool written in C++ that allows you to generate random passwords and apply hash masks for added security.

## Features

- Generate random passwords with customizable length.
- Optionally apply a hash mask to the generated password.

## How to Use

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/jimboo420/SafeKeyMaker.git
   cd SafeKeyMaker
   
2. Compile the program using a C++ compiler:
   ```bash
   g++ main.cpp -o password_generator

3. Run the executable:
   ```bash
   ./password_generator
   
Follow the prompts to specify the desired password length and whether to apply a hash mask.

Enter the desired password length: 12
Generated Password: 1aB$eF!gH*jK
Do you want to apply a hash mask? (y/n): y
Enter the hash mask: secretmask
Password with Hash Mask: 2d4e1f1a534b0b59072e040b
Press any key to generate another password, or press 'x' to exit: <Press any key>



Feel free to contribute, report issues, or suggest enhancements.

Happy password generating!




