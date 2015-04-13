#define DEBUG if(1)
#define errlist cerr

class errcheck
{
	public:
		symtable table;
		bool err; 
		int inLoop;
		symbol* infunc;
		//stringstream errlist;
		errcheck(ttnode *t)
		{
			if(t == NULL) return;
			err = false;
			inLoop = 0;
			infunc = new symbol("default",t_none);
			check(t);
		}
		
		void check(ttnode *t)
		{
			//if(t != NULL) DEBUG cerr << t -> identifier <<' ' << t -> item << endl;
			if(t == NULL) return;
			else if(t -> identifier == "variable_declaration")		vardec(t);
			else if(t -> identifier == "function_declaration") 		fundec(t); 		
			else if(t -> identifier == "main_function")				maincheck(t); 	
			else if(t -> identifier == "variable")					varcheck(t);	
			else if(t -> identifier == "statement")					statcheck(t);	
			else if(t -> identifier == "condition_stat")			concheck(t);	
			else if(t -> identifier == "for_loop")					forcheck(t);	
			else if(t -> identifier == "while_loop")				whilecheck(t);	
			else if(t -> identifier == "return_stat")				retcheck(t);	
			else if(t -> identifier == "expression")				expcheck(t);	
			else if(t -> identifier == "and_expression")			boolecheck(t);	
			else if(t -> identifier == "logic_expression")			boolecheck(t);	
			else	{check(t->first); check(t->second); check(t->third);}
		}
		
		void vardec(ttnode *t)
		{
			vector<string> v = generatevars(t->second);
			for(int i=0;i<v.size();i++)
			{
				if(table.lookup_curscope(v[i]))
				{
					errlist << "Redeclared " << v[i] << endl;
					err = true;
					continue;
				}
				table.add_var(symbol(v[i]));
				DEBUG cerr << "declared " << v[i] << endl;
			}
		}
		
		void fundec(ttnode *t)
		{
			if(t->third != NULL)
			{
				vector<param> v = generatepars(t->second->first);
				if(table.lookup(t->item) != string() and table.getparams(t->item).size() == v.size())
				{
					errlist << "Redeclared " << t -> item << ' ' << "with " << v.size() << "parameters" << endl;
					err = true;
				}
				table.add_var(symbol(t->item,t_func,v));
				infunc = new symbol(t->item,t_func,table.getType(t->first->item),v);
				table.add_scope();
				for(int i=0;i<v.size();i++)
				{
					table.add_var(symbol(v[i].name));
					DEBUG cerr << "parameter " << v[i].name << endl;
				}
				check(t->third);
			}
			else
			{
				vector<param> v = generatepars(t->first->first);
				table.add_var(symbol(t->item,t_func,v));
				infunc = new symbol(t->item,t_func,v);
				table.add_scope();
				for(int i=0;i<v.size();i++)
				{
					table.add_var(symbol(v[i].name));
				}
				check(t->second);	
			}
			table.remove_scope();
			infunc -> type = t_none;
		}
		
		void maincheck(ttnode *t)
		{
			table.add_scope();
			check(t->first);
			table.remove_scope();
		}
		
		void varcheck(ttnode *t)
		{
			if(table.lookup(t->first->item) == string())
			{
				errlist << t->first->item <<  " not declared " << endl;
				err = true;
				return;
			}
			t -> type = table.lookupX(t->first->item).type;
		}
		
		void statcheck(ttnode *t)
		{
			if(t->item == "break")
			{
				DEBUG cerr << "Found Break\n";
				if(!inLoop)
				{
					errlist << "Found break without loop\n";
					err = true;
				}
			}
			else if(t->item == "continue")
			{
				DEBUG cerr << "Found Continue\n";
				if(!inLoop)
				{
					errlist << "Found continue without loop\n";
					err = true;
				}
			}
			else
				check(t->first);
		}
		
		void concheck(ttnode* t)
		{
	
			check(t->first);
			table.add_scope();
			check(t->second);
			table.remove_scope();
			if(t->item == "op")
			{
				table.add_scope();
				check(t->third);
				table.remove_scope();
			}
		}
		
		void forcheck(ttnode *t)
		{
			inLoop++;
			check(t->first);
			check(t->second);
			table.add_scope();
			check(t->third);
			table.remove_scope();
			--inLoop;
		}
		
		void whilecheck(ttnode *t)
		{
			inLoop++;
			check(t->first);
			table.add_scope();
			check(t->second);
			table.remove_scope();
			--inLoop;
		}
		
		void retcheck(ttnode *t)
		{
			if(infunc -> type == t_none)
			{
				errlist << "Whoa! Return to mars? Found return without function\n";
				err = true;
				return;
			}
			else if(t->item == "op")
			{
				check(t->second);
				if(t->second->type != infunc->ret_type)
				{
					errlist << "Return type mismatch in function " << infunc->name << endl;
					DEBUG cerr << table.typetostring(t->second->type) << ' ' << table.typetostring(infunc->ret_type) << endl; 
					err = true;
				}
				DEBUG cerr << "Return with op" << endl;
			}
			else
			{
				DEBUG cerr << "Return without op" << endl;
			}
		}
		
		void expcheck(ttnode *t)
		{
			if(t->item == "=")
			{
				check(t -> second);
				Type t1 = t -> second -> type;
				check(t -> first);
				Type t2 = t -> first -> type;
				if(t1 != t2)
				{
					errlist << "Expression type mismatch." << endl;
					DEBUG cerr << t1 << ' ' << t2 << endl; 
					err = true;
				}
				t -> type = t -> first -> type;
			}
			else
			{
				check(t -> first);
				t -> type = t -> first -> type;
			}
		}
		
		void boolecheck(ttnode *t)
		{
			if(t->item == "and" || t -> item == "or")
			{
				check(t->second);
				Type t1 = t -> second -> type;
				check(t->first);
				Type t2 = t -> first -> type;
				if(t1 != t2)
				{
					errlist << "Expression type mismatch." << endl;
					err = true;
				}
				t -> type = t_bool;
			}
			else
			{
				check(t -> first);
				t -> type = t -> first -> type;
			}
		}
		
		vector<Type> generateargtype(ttnode *t)
		{
			vector<Type> v;
			if(t->item != "epsilon")
			{
				if(t->second == NULL)
				{
					check(t -> first);
					v.push_back(t -> second -> type);
				}
				else
				{
					v = generateargtype(t->first);
					check(t -> second);
					v.push_back(t -> second -> type);
				}
			}
			return v;
		}
		
		void callcheck(ttnode *t)
		{
			if(table.lookup(t->item) == string())
			{
				errlist << t->item << " function not declared." << endl;
				err = true;
				return;
			}
			
			vector<Type> v = generateargtype(t->first->first);
			vector<Type> pars = table.getparamtype(t->item);
			if(v.size() != pars.size())
			{
				errlist << t->item << ": " << pars.size() <<" parameters are allowed. " << v.size() << " passed." << endl;
				err = true;
				return;
			}
		
			for(int i = 0; i < v.size(); i++)
			{
				if(v[i] != pars[i])
				{
					errlist << "Type mismatch for parameter " << i+1 << " in " << t -> item << ". " ;
					errlist << table.typetostring(pars[i]) << " required. " << table.typetostring(v[i]) << " given." << endl;
					err = true;
					return;
				}
			}
			
			t -> type = table.lookupX(t->item).ret_type;
		}
};	
