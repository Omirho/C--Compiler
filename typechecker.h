#define DEBUG if(1)

class errcheck
{
	public:
		symtable table;
		bool err; 
		int inLoop;
		symbol* infunc;
		stringstream errlist;
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
			if(t == NULL) return;
			else if(t -> identifier == "variable_declaration")		vardec(t);
			else if(t -> identifier == "function_declaration") 		fundec(t); 		
			else if(t -> identifier == "main_function")				maincheck(t); 	
			else if(t -> identifier == "variable")					varcheck(t);	
			else if(t -> identifier == "statement")					statcheck(t);	
			else if(t -> identifier == "condition_stat")			concheck(t);	
			else if(t -> identifier == "for_loop")					forcheck(t);	
			else if(t -> identifier == "while_loop")				whilecheck(t);	
			
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
			if(t->item == "op")
			{
				check(t->second);
				if(t->second->type != infunc->ret_type)
				{
					errlist << "Return type mismatch in function \n" << infunc->name << endl;
					err = true;
				}
				DEBUG cerr << "return with op" << endl;
			}
			else
			{
				DEBUG cerr << "Return without op" << endl;
			}
		}
};
