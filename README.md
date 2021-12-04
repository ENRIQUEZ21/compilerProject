# compilerProject

These instructions are on Windows

# Install Lex 
To install Flex (Lex) on Windows, you must proceed as following: 
- Go to the link : https://sourceforge.net/projects/gnuwin32/files/flex/2.5.4a-1/flex-2.5.4a-1.exe/download?use_mirror=deac-ams&download= 
- Install the .exe file in your PC
- Add the PATH to the system environment variables (/bin path)

# Install MinGW to compile C code 
- Go to the link https://sourceforge.net/projects/mingw/ and download the .exe file
- Install it on your PC 
- Add the PATH to the system environment variable  (/bin path)

# Run the code 
- Clone the project in your PC with the following command : git clone https://github.com/ENRIQUEZ21/compilerProject.git 
- with your Terminal go to the compilerProject folder, and run the command `flex Compiler.l` to generate a lex.yy.c C file 
- Then, run the command `gcc lex.yy.c -o output` to create an output 
- After that launch `output` in your Terminal and enter a string to test the program
