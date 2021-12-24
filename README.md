# compilerProject

These instructions are on Windows

#LEXICAL ANALYSIS

# Install Lex 
To install Flex (Lex) on Windows, you must proceed as following: 
- Go to the link : https://sourceforge.net/projects/gnuwin32/files/flex/2.5.4a-1/flex-2.5.4a-1.exe/download?use_mirror=deac-ams&download= 
- Install the .exe file in your PC
- Add the PATH to the system environment variables (/bin path)

# Install MinGW to compile C code 
- Go to the link https://sourceforge.net/projects/mingw/ and download the .exe file
- Install it on your PC 
- Add the PATH to the system environment variable  (/bin path)


# Install Bison 
To install Bison on Windows, follow the instructions of the following video: https://www.youtube.com/watch?v=cBUBN_B_vm4 

# Run the code
- Clone the project in your PC with the following command : git clone https://github.com/ENRIQUEZ21/compilerProject.git 
- with your Terminal go to the compilerProject foder and launch the command `bison -d yacc.y` to generate yacc.tab.h file and yacc.tab.c file.
- with your Terminal go to the compilerProject folder, and run the command `flex lexer.l` to generate the lex.yy.c C file 
- Then, run the command `gcc -o a yacc.tab.c lex.yy.c` to create an a.exe executable file 
- After that launch `a.exe input.txt` in your Terminal to parse the pseudo-code in the input.txt text file
