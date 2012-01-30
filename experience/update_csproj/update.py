#!/bin/env python
############################################################################
# use: python update.py PUBLIC_KEY_TOKEN (assembly strong name)
# The script will downward recursively update all the csproj files so that
# the new csproj files will reference Enterprise Library 4.1.0.0 PLUS its
# hint path is appended with a subdirectory "4.1.0.0"
############################################################################

import os
import sys
from xml.dom import minidom

#assumption: public key is the same, has hintpath, has version 3.1.0.0

#assumption: only one csproj in each directory
def replace_original_csproj():
	all_files = os.walk(os.getcwd())
	for i in all_files:
		two_proj_files = []
		for k in i[2]:
			full_path = os.path.join(i[0],k)
			if full_path.find(".csproj") != -1:
				two_proj_files.append(full_path)

	        #assertion check
		if len(two_proj_files) > 0:
			assert len(two_proj_files) == 2, "csproj and its 4.1.0.0 do not match."
			tmp_file_name = ""
			if two_proj_files[0] > two_proj_files[1]:
				tmp_file_name = two_proj_files[1]
				os.remove(two_proj_files[1])
				os.rename(two_proj_files[0], tmp_file_name)
			else:
				tmp_file_name = two_proj_files[0]
				os.remove(two_proj_files[0])
				os.rename(two_proj_files[1], tmp_file_name)
				

def get_all_csproj_files_fullpath():
	all_files = os.walk(os.getcwd())
	csproj_files = []
	for i in all_files:
		for k in i[2]:
			full_path = os.path.join(i[0],k)
			if full_path.rfind("csproj") != -1:
				if full_path.rfind("csproj")+len("csproj")-1 == len(full_path) -1: 
					csproj_files.append(full_path)
	
	return csproj_files


def remove_all_files_added_by_this_script(file_suffix):
	all_files = os.walk(os.getcwd())
	for i in all_files:
		for k in i[2]:
			full_path = os.path.join(i[0], k)
			if full_path.find(file_suffix) != -1:
				os.remove(full_path)
				print "\nremove " +  full_path

def parse_include_attribute(include_string, new_public_key_token):
	new_include_attribute = ""
	tokens = include_string.split(",")
	token_length = 1
	debug_find_version = False
	debug_find_public_key_token = False
	for i in tokens:
		result = ""
		i = i.strip()
		if i.find("Version=3.1.0.0") != -1:
			result = "Version=4.1.0.0"
			debug_find_version = True
		elif i.find("PublicKeyToken=") != -1:
                        result = "PublicKeyToken=" + new_public_key_token
			debug_find_public_key_token = True

                else:
			result = i

		if token_length != len(tokens):
			if token_length != 1:
				new_include_attribute = new_include_attribute + ", " + result
			else:
				new_include_attribute = result
                else:
			new_include_attribute = new_include_attribute + ", " + result

		token_length = token_length + 1
	
	assert debug_find_version, "method parse_include_attribute: Version=3.1.0.0 not found"
	assert debug_find_public_key_token, "method parse_include_attribute: PublikcKeyToken not found"

	return new_include_attribute

def parse_hintpath_element(hintpath_content, folder_append):
	tokens = hintpath_content.split("\\")
	new_hintpath_content = ""
	token_length = 1
	for i in tokens:
		i = i.strip()
		if token_length == len(tokens) - 1:
			new_hintpath_content = new_hintpath_content + i + "\\" + folder_append + "\\"
		elif token_length == len(tokens):
			new_hintpath_content = new_hintpath_content + i
		else:
			new_hintpath_content = new_hintpath_content + i + "\\"

		token_length = token_length + 1

	return new_hintpath_content	

def update_version_and_key(file_name, publickey_token, file_suffix):
	xmldoc = minidom.parse(file_name)
	reference_count = 0
	reflist = xmldoc.getElementsByTagName("Reference")
	include_list = []
	for i in reflist:
		reference_count = reference_count + 1
		include_list.append(i.getAttribute("Include"))

        #Assertion check
		assert_message = "reference_count != include_count, some reference might be missing in the project file(csproj, vsproj)"
		assert reference_count == len(include_list), assert_message

	
	enterprise_library_namespace = "Microsoft.Practices.EnterpriseLibrary"	

	for i in reflist:
		content = i.getAttribute("Include")
		if content.find("Version=3.1.0.0") != -1 and content.find(enterprise_library_namespace) != -1:
			i.setAttribute("Include", parse_include_attribute(content, publickey_token))

		
	#print "----"

	hintlist = xmldoc.getElementsByTagName("HintPath")
	for i in hintlist:
		if i.firstChild.data.find(enterprise_library_namespace) != -1:
			i.firstChild.data = parse_hintpath_element(i.firstChild.data, "4.1.0.0")
			#print i.firstChild.data

		
        fp = open(file_name+file_suffix, "w")
	xmldoc.writexml(fp, "", "", "", "UTF-8")

def main():
        if len(sys.argv) < 2:
            print "Missing public key token"
            print "Usage: python update.py PUBLIC_KEY_TOKEN"
            sys.exit(2)
        
	file_suffix = ".Version4.1.0.Practices.EnterpriseLibrary"
	if sys.argv[1] == "rm":
		remove_all_files_added_by_this_script(file_suffix)
	else:
		public_key_token = sys.argv[1]
		all_target_project_file = get_all_csproj_files_fullpath()
		for i in all_target_project_file:
			print "...Processing " + i
			update_version_and_key(i,public_key_token, file_suffix)
			#print "...Save as new " + i + file_suffix 
			print "---"
			
                #now replace the csproj file for real
		replace_original_csproj()

        print "\nDone."


if __name__ == '__main__':
	main()




