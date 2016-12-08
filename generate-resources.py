#! /usr/bin/python2

import os
import shutil
import zipfile
from hurry.filesize import size

def Generate(xDir, xExt):
	fileList = []
	nFileList = []
	tSize = 0
	
	for root, dirs, files in os.walk("./presources/" + xDir):
		for file in files:
			if file.endswith(xExt):
				target = os.path.join(root, file)
				fileList.append(target)
				tSize += os.path.getsize(target)
	
	print "Found " + str(len(fileList)) + " " + xExt + " file(s) in ./presources/" + xDir
	
	if not os.path.exists("./resources"):
		os.makedirs("./resources")
	
	if not os.path.exists("./resources/" + xDir):
		os.makedirs("./resources/" + xDir)
	
	for file in fileList:
		target = "./resources/" + xDir + "/" + file.replace("./presources/" + xDir + "/", "").replace("/", "_")
		shutil.copy2(file, target)
		nFileList.append(target)
	
	print "Copied " + str(len(nFileList)) + "/" + str(len(fileList)) + " " + xExt + " file(s) to ./resources/" + xDir
	
	zip = zipfile.ZipFile("./resources/" + xDir + ".zip", "w", zipfile.ZIP_DEFLATED)
	for file in nFileList:
		zip.write(file, file.replace("./resources/" + xDir + "/", ""))
	zip.close()
	
	print "Created " + xDir + ".zip" 
	print "Old size " + size(tSize)
	print "New size " + size(os.path.getsize("./resources/" + xDir + ".zip"))

Generate("other", "")
