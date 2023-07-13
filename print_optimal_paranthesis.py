# Python3 program to print optimal parenthesization
# in matrix chain multiplication.
name = 0;

# Function for printing the optimal
# parenthesization of a matrix chain product
def printParenthesis(i , j, n, bracket):
	
	global name

	# If only one matrix left in current segment
	if (i == j):
	
		print(name, end = "");
		name = chr(ord(name) + 1)
		return;
	
	print("(", end = "");

	# Recursively put brackets around subexpression
	# from i to bracket[i][j].
	# Note that "*((bracket+i*n)+j)" is similar to
	# bracket[i][j]
	printParenthesis(i, bracket[i][j], n, bracket);

	# Recursively put brackets around subexpression
	# from bracket[i][j] + 1 to j.
	printParenthesis(bracket[i][j] + 1, j, n, bracket);
	print(")", end = "");

# Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
# Please refer below article for details of this
# function
# https:#goo.gl/k6EYKj
def matrixChainOrder( p , n):
	
	global name

	'''
		* For simplicity of the program,
		one extra row and one extra column are
		* allocated in m. 0th row and
		0th column of m are not used
		'''
	m = [ [0 for _ in range(n)] for _ in range(n)]

	# bracket[i][j] stores optimal break point in
	# subexpression from i to j.
	bracket = [ [0 for _ in range(n)] for _ in range(n)]

	'''
		* m[i,j] = Minimum number of scalar
		multiplications needed to compute the
		* matrix A[i]A[i+1]...A[j] = A[i..j] where
		dimension of A[i] is p[i-1] x p[i]
		'''

	# cost is zero when multiplying one matrix.
	for i in range(1, n):
		m[i][i] = 0;

	# L is chain length.
	for L in range(2, n):
		
		for i in range(1, n - L + 1):
			j = i + L - 1;
			m[i][j] = 10 ** 8;
			for k in range(i, j):

				# q = cost/scalar multiplications
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) :
		
					m[i][j] = q;

				# Each entry bracket[i,j]=k shows
				# where to split the product arr
				# i,i+1....j for the minimum cost.
				bracket[i][j] = k;
		
	# The first matrix is printed as 'A', next as 'B',
	# and so on
	name = 'A';
	print("Optimal Parenthesization is : ");
	printParenthesis(1, n - 1, n, bracket);
	print("\nOptimal Cost is :", m[1][n - 1]);

# Driver code
arr = [ 40, 20, 30, 10, 30 ];
n = len(arr);
matrixChainOrder(arr, n);

