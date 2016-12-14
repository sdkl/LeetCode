#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool isMatch(const string& s1, const string& s2)
	{
		int n = 0;
		for (int i = 0; i < s1.size() && n < 2; i++)
		{
			if (s1[i] != s2[i])
				n++;
		}
		return n == 1;
	}

	void getAllPath(vector<vector<string>> &result, unordered_map<string, vector<string>> &childMap, string &beginWord, string &endWord, vector<string> &path, int &minSize)
	{
		if (path.size() == minSize)
			return;
		path.push_back(beginWord);
		if (childMap.count(beginWord) == 0)
		{
			if (path.size() == minSize && beginWord.compare(endWord) == 0)
				result.push_back(path);
		}			
		else
		{
			for (auto str : childMap[beginWord])
			{
				getAllPath(result, childMap, str, endWord, path, minSize);
			}
		}
		path.pop_back();
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<string> path, queue = { beginWord };
		unordered_map<string, vector<string>> childMap;
		unordered_set<string> usedList;
		vector<vector<string>> result;
		bool finish = false;
		int minSize = 1;
		wordList.erase(beginWord);
		wordList.insert(endWord);

		while (queue.size() > 0)
		{
			minSize++;
			vector<string> n;

			for (auto str1 : queue)
			{
				for (auto str2 : wordList)
				{
					if (isMatch(str1, str2))
					{
						childMap[str1].push_back(str2);
						if (usedList.count(str2) == 0)
						{
							usedList.insert(str2);							
							n.push_back(str2);
							if (endWord.compare(str2) == 0)
								finish = true;
						}
						
					}
				}				
			}
			for (auto str : n)
				wordList.erase(str);

			queue = n;
			if (finish)
			{
				childMap.erase(endWord);
				getAllPath(result, childMap, beginWord, endWord, path, minSize);
				return result;
			}
		}

		return{};
	}
};

int main()
{
	Solution s;
	/*unordered_set<string> list = { "hot", "dot", "dog", "lot", "log" };
	vector<vector<string>> r = s.findLadders("hit", "cog", list);*/
	/*unordered_set<string> list = { "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die", "war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali", "pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", "ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana", "gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", "sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye", "oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm", "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron", "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub", "ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam", "new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set", "qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro", "few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw", "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", "bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin", "mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi", "yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref", "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob" };
	vector<vector<string>> r = s.findLadders("cet", "ism", list);*/
	/*unordered_set<string> list = { "ted", "tex", "red", "tax", "tad", "den", "rex", "pee" };
	vector<vector<string>> r = s.findLadders("red", "tax", list);*/
	unordered_set<string> list = { "a", "b", "c"};
	vector<vector<string>> r = s.findLadders("a", "c", list);
	for (auto i : r)
	{
		for (auto j : i)
		{
			cout << j.c_str() << "->";
		}
		cout << endl;
	}

	getchar();
	return 0;
}