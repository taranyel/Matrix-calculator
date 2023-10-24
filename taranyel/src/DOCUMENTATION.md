It is a <b>matrix calculator</b> - an interactive application for calculating expressions with matrices and numbers. Operands can also be stored in variables. The calculator uses postfix notation to evaluate expressions! Examples: <br>

2 MUL (3 + 1) - 9 will be <br>
2 3 1 + MUL 9 - <br>
Result: -1 <br>

X = [[3, 5], [1, 2]] <br>
Y = [[7, 8], [0, 0]] <br>

DET ((X + Y MUL 2)) MUL [[2, 3, 0], [0, 9, 7]] will be <br>
X Y 2 MUL + DET [[2, 3, 0], [0, 9, 7]] MUL <br>
Result:  <br>
26 39 0 <br>
0 117 91


The calculator is controlled by the following commands:
<ul>
<li>SCAN [variable name] - scans operand from standart input;</li> <br>
<li>PRINT [variable name] - prints operand to a given output stream;</li> <br>
<li>IMPORT [file name] - imports data from a file. You can also add [variable name] parameter if you want to import only one variable;</li> <br>
<li>EXPORT [file name] - exports data to a file. You can also add [variable name] parameter if you want to export only one variable;</li> <br>
<li>DELETE [variable name] - deletes operand from calculator memory;</li> <br>
<li>EXIT - exits program;</li> <br>
<li>HELP - prints help information about application.</li> <br>
</ul>


The calculator supports the following operators:

<ul>
<li>DET - calculates determinant of matrix;</li> <br>
<li>GAUSS - finds the row echelon form of the matrix;</li> <br>
<li>INV - calculates the inverse matrix of the original matrix;</li> <br>
<li>ADD - merges two matrices into one matrix;</li> <br>
<li>"-" - substracts two matrices or numbers;</li> <br>
<li>"+" - sums two matrices or numbers;</li> <br>
<li>MUL - multiplies two matrices or numbers;</li> <br>
<li>RANK - calculates matrix rank;</li> <br>
<li>TRANS - transposes matrix;</li> <br>
<li>TRIM - trims matrix according to the size other matrix with offset 0x0.</li> <br>
</ul>

Example of calculator work:

Enter your command: <br>
SCAN X <br>
Enter your number or matrix in form [[.., ...], ...., [.., ...]]<br>
[[1, 2], [4, 5]] <br>
Enter your command: <br>
Z = X 5 MUL <br>
Your variable Z: <br>
5 10 <br>
20 25 <br>
Enter your command: <br>
DELETE Z <br>
Successfully deleted! <br>
Enter your command: <br>
PRINT Z <br>
Variable does not exist! <br>
Enter your command: <br>
EXIT <br>
See you soon! 