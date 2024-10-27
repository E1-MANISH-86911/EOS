#15. Accept the two file names from user and append the contents in reverse case of first file
#into second file.
echo "Enter the name of 1st file: "
read file1
echo "Enter the name of 2nd file: "
read file2
tr 'a-zA-Z' 'A-Za-z' < "$file1" >> "$file2"
