* Insertion of node at a given position
*/
void single_llist::insert_pos()
{
 int value, pos, counter = 0;
 cout<<"Enter the value to be inserted: ";
 cin>>value;
 struct node *temp, *s, *ptr;
 temp = create_node(value);
 cout<<"Enter the postion at which node to be inserted: ";
 cin>>pos;
 int i;
 s = start;
 while (s != NULL)
 {
 s = s->next;
 counter++;
 }
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
