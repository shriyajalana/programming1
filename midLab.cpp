 if (pos == 1)
 {
 if (start == NULL)
 {
 start = temp;
 start->next = NULL;
 }
 else
 {
 ptr = start;
 start = temp;
 start->next = ptr;
 }
 }
 else if (pos > 1 && pos <= counter)
 {
 s = start;
 for (i = 1; i < pos; i++)
 {
 ptr = s;
 s = s->next;
 }
 ptr->next = temp;
 temp->next = s;
 }
 else
 {
 cout<<"Positon out of range"<<endl;
 }
}
