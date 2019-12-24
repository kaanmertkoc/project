
function justMove() {
	numberOfInputs=$#
	echo $numberOfInputs
	if [ $numberOfInputs -eq 3 ]
	then
		cd $1
		mv $2 $3
	else
		echo 'You need to give one input for the file s path '
		echo ' for file name and one for the destination path'
	fi

}
function moveWithNoOwerrite() {
	
	numberOfInputs=$#
	echo $numberOfInputs
	if [ $numberOfInputs -eq 3 ]
	then
		cd $1
		mv -n $2 $3
	else
		echo 'You need to give one input for the file s path '
		echo ' for file name and one for the destination path'
	fi
}
function moveWithVerbose() {
	numberOfInputs=$#
	echo $numberOfInputs
	if [ $numberOfInputs -eq 3 ]
	then
		cd $1
		mv -v $2 $3
	else
		echo 'You need to give one input for the file s path '
		echo ' for file name and one for the destination path'
	fi
}


	


