
function peek(){
	inputs=$#
	if [ $inputs -eq 1 ]; then
		cat $1
	else
		echo "You need to enter a file name with path "
	fi
}
function peekWithLineNumbers(){
	inputs=$#
	if [ $inputs -eq 1 ]; then
		cat -n $1 
	else
		echo "You need to enter a file name with path "
	fi
	
}
function peekWithNonPrintingCharacters(){
	inputs=$#
	if [ $inputs -eq 1 ]; then
		cat -t $1 
	else
		echo "You need to enter a file name with path "
	fi
}
function peekNonPrintingCharacters(){
	inputs=$#
	if [ $inputs -eq 1 ]; then
		cat -e $1  
	else
	echo "You need to enter a file name with path "
	fi
}