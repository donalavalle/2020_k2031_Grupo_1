all:
	if not exist "bin" mkdir bin
	attrib +h "bin"
	bison -d -v AnalizadorSintactico.y
	flex AnalizadorLexico.l
	gcc AnalizadorSintactico.tab.c lex.yy.c -o Ejecutable
	move lex.yy.c "bin"
	move AnalizadorSintactico.tab.c "bin"
	move AnalizadorSintactico.tab.h "bin"
	move AnalizadorSintactico.output "bin"
	cmd /c .\Ejecutable.exe