extern int yylineno;
ttnode *make_node(string sval,string identifier, ttnode *n1, ttnode *n2, ttnode *n3)
{
	ttnode *n = new ttnode();
	n->item = sval;
	n->identifier = identifier;
	n->first = n1;
	n->second = n2;
	n->third = n3;
	n->line_num = yylineno;
	return n;
}

vector<bool> line;

ofstream fout("tree.txt");
void printtreeold(ttnode *t, string term)
{
	if(t==NULL) return;
	if(!line.empty()) fout << "    \t";
	for(int i = 0; i < (int)line.size() - 1; i++) if(line[i]) fout << "¦   \t"; else fout << "    \t";
	fout << term; 
	fout << t->identifier;
	if((t->item).size())
		fout << "( " << t->item << " )";
	fout << endl;
	if(t->second) {line.push_back(1); printtreeold(t->first,"+-- "); line.pop_back();}
	else {line.push_back(0); printtreeold(t->first,"+-- "); line.pop_back();}
	if(t->third) {line.push_back(1); printtreeold(t->second, "+-- "); line.pop_back();}
	else {line.push_back(0); printtreeold(t->second, "+-- "); line.pop_back();}
	{line.push_back(0); printtreeold(t->third, "+-- "); line.pop_back();}
}

int print(string par, string child){
	if(par == "begin") 
	{
		cout << "digraph G {\n";
		cout << "begin [shape=box,style=filled,color=white]\n";
		cout << "\"" << par << "\" " << "[label = \"\"];\n";
	}
	else 
	cout << "\"" << par << "\" " << "[label = \"" << par.substr(par.find_first_of('.') + 1) << "\"];\n";
	cout << "\"" << child << "\" " << "[label = \"" << child.substr(child.find_first_of('.') + 1) << "\"];\n";
    cout<<"\""<<par<<"\""<<" -> "<<"\""<<child<<"\""<<endl;
    return 0;
}

int cnt = 0;

void printtree(ttnode *t,string parent="begin"){
	if(t==NULL) return;
	string s="";
    cnt++;
	stringstream s1;
    s1<<cnt;
    s = s1.str()+ ". ";
	s+=t->identifier+" ";
	if((t->item).size())
		s+="( " + t->item + " )";
    print(parent,s);
	printtree(t->first, s);
	printtree(t->second, s);
	printtree(t->third, s);
	if(parent == "begin") cout << "}";
}