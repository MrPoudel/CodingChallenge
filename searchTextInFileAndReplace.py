#!/usr/bin/python

import os
import sys


#################################### Parsing the OHS_HOST ################################
# Open the file in read mode 
text = open("osh_host", "r") 
  
# First create a dictionary with distinct keys from osh_host file
# And later search each key in all the files

d = dict() 
  
# Loop through each line of the file 
for line in text: 
    # Remove the leading spaces and newline character 
    line = line.strip() 
    
    #print(line)

    # Convert the characters in line to  
    # lowercase to avoid case mismatch 
    line = line.lower() 
  
    # Split the line into words 
    words = line.split(" ") 
  
    # Iterate over each word in line 
    for word in words: 

        if word.startswith('[eu_osx'):  #since its all type str you can simply use startswith
            print('Discarded key {}'.format(word))

        else:
            # Check if the word is already in dictionary 
            if word in d: 
                # Increment count of word by 1 
                d[word] = d[word] + 1
            else: 
                # Add the word to dictionary with count 1 
                d[word] = 1
  
# Print the contents of dictionary, i.e. search keywords 
for key in list(d.keys()): 
    print(key, ":", d[key])

#val = 'b045842c175c29d80ec1743de7f22e0e1671e31a'


#############Searching in  the list of target files, just add the list as per your need #############

# Read in the first file whose content has to be replaced!
FILE = ['file1.txt', 'file2.txt']
for eh in FILE:
    with open(eh, 'r') as file :
        filedata = file.read()

#words = filedata.split()
#for w in words:
#    print(w)

    # Replace the target string
    for i in d:
        print('Searching for UID {} in {}'.format(i, eh))
        filedata = filedata.replace(i, 'REPLACED')

    # Write the file out again
    with open(eh, 'w') as file:
        file.write(filedata)   

