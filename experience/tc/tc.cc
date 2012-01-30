/*****************************************
  Dragonfly TRANSLATION KEY CHECKER v0.01
    Desired Features:
    --check duplicate keys
    --check untranslated values
    --group keys by xaml page
 *****************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Language {
public:
  Language(const string &file_name);
  map<string, string> get_key_value_map() { return key_value_map; }
  bool check_untranslated_string_against_eng(const map<string, string>& map);
private:
  string extract_key(const string line);
  string extract_value(const string line);
  void display_key(const vector<string> &vec);
  void display_key(const map<string, int> &mp);
  void display_key_value(const map<string, string> &mp);
  void display_duplicate_key();
  void check_duplicate(const map<string, int> &mp);
  bool check_duplicate(vector<string> vec);
  
  int get_total_unique_keys();
  

  string file_name;
  string line;
  string key;
  bool hasDuplicate;
  vector<string> duplicate;
  int line_count; //?cannot initialize value here? ISO forbid?
  vector<string> lines_of_text;
  vector<string> all_keys;
  map<string, int> key_count_map;
  map<string, string> key_value_map;
  map<string, string> possible_untranslated_map;
};

Language::Language(const string &hardcode_file_name):line_count(0),file_name(hardcode_file_name), hasDuplicate(false)
{
    ifstream infile(hardcode_file_name.c_str()); //why c_str()
    if (!infile)  // (infile, cin.good) cool
      {
	cerr << "Error: unable to open " << hardcode_file_name << endl;
	exit(-1);
      }

    while ( getline(infile, line, '\n') )
      {
	lines_of_text.push_back(line);
	++line_count;

	if ( (key = extract_key(line)) != "")
	  {
	    all_keys.push_back(key);
	    ++key_count_map[key];
	    key_value_map[key] = extract_value(line);
	  }
      }

    cout << endl;
    cout <<  "***************************************" << endl;
    cout <<  file_name << endl;

    check_duplicate(key_count_map);
    if (hasDuplicate)
      {
	cout << "(might contain duplicate key)" << endl;
	cout << "please check the following " ;
	cout << (duplicate.size() > 1 ? "keys:\n": "key:\n");
	display_duplicate_key();
      }
    else
      {
	//cout << file_name << " no duplicate key" << endl;
      }

    cout << "Total Unique Keys: " << get_total_unique_keys() << endl;
}

string Language::extract_key(const string line)
{
  string::size_type pos;
  const string::size_type key_length = string("Key=\"").size();

  pos = line.find("Key=");
  if( pos != string::npos)
    {
      pos += key_length;
      string substring;
      substring = line.substr(pos);
      substring = substring.substr(0, substring.find("\""));

      return substring;
    }

  return "";
}

string Language::extract_value(const string line)
{
  string::size_type pos;
  const string::size_type value_length = string("Value=\"").size();
  pos = line.find("Value=");
  if( pos != string::npos)
    {
      pos += value_length;
      string substring;
      substring = line.substr(pos);
      substring = substring.substr(0, substring.find("\""));

      return substring;
    }
 
  return "";
}

void Language::display_key(const vector<string> &vec)
{
  for(vector<string>::const_iterator iter = vec.begin();
      iter != vec.end(); ++iter)
    {
      cout << *iter << endl;
    }
}

void Language::display_key(const map<string, int> &mp)
{
  for(map<string, int>::const_iterator iter = mp.begin();
      iter != mp.end(); ++iter)
    {
      cout << iter->first << endl;
    }
}

void Language::display_key_value(const map<string, string> &mp)
{
  for(map<string, string>::const_iterator iter = mp.begin();
      iter != mp.end(); ++iter)
    {
      cout << "Key=" << iter->first << " Value=" << iter->second << endl;
      //learn: iter->first == (*iter).first , old libraries support the later
    }
}

void Language::display_duplicate_key()
{
  for(vector<string>::const_iterator iter = duplicate.begin();
      iter != duplicate.end(); ++iter)
    {
      cout << "--" << *iter << endl;
    }
}

void Language::check_duplicate(const map<string, int> &mp)
{
  for(map<string, int>::const_iterator iter = mp.begin();
      iter != mp.end(); ++iter)
    {
      if( iter->second >1) 
	{
	  hasDuplicate = true;
	  duplicate.push_back(iter->first);
	}
    }
}

bool Language::check_duplicate(vector<string> vec)
{
  sort(vec.begin(), vec.end());

  vector<string>::const_iterator new_end;
  new_end = unique(vec.begin(),vec.end());

  if (new_end != vec.end())
    {
      cout << "Warnning: Duplicate keys" << endl;
           
      return false;
    }

  return true;
}

bool Language::check_untranslated_string_against_eng(const map<string,string>& eng_map)
{
  bool result = true;

  if ( key_value_map.size() > eng_map.size())
    {
      cout << "Eng has more keys than the current language\n"
           << ",cannot check untranslated strings! " << endl;
      return false;
    }
  if (key_value_map.size() < eng_map.size())
    {
      cout << "Eng has less keys than the current language,\n"
           << ",cannot check untranslated strings! " << endl;
      return false;
    }

  map<string, string>::const_iterator iter = key_value_map.begin();
  map<string, string>::const_iterator eng_iter = eng_map.begin();

  for (; iter != key_value_map.end(), eng_iter != eng_map.end();
       ++iter, ++eng_iter)
    {
      if (*iter == *eng_iter)
	{
	  possible_untranslated_map[iter->first] = iter->second; 
	  result = false;

	  //debug
	  cout << "possible untranslated: key=" << iter->first 
               << " value=" << iter->second << endl;
	}
    }  

  return result;
}

int Language::get_total_unique_keys()
{
  return key_value_map.size();
}


int main()
{
  /*
  Language EN(EN_FILE);
  Language DE(DE_FILE);
  DE.check_untranslated_string_against_eng(EN.get_key_value_map());
  Language ES(ES_FILE);
  Language FR(FR_FILE);
  Language JP(JP_FILE);
  Language PT(PT_FILE);  
  */
}
