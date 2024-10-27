#12. Write a shell script to accept a filename as argument and displays the last modification
#time if the file exists and a suitable message if it doesn’t exist.
#!/bin/bash
echo "Enter file name: "
read filename
if [ -f $filename ]
then
stat -c %y $filename
else
echo "Invalid file name"
fi

