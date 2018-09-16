pair<State,State> read_problem(char* filename)
{
  int nstacks=-1,nblocks=-1;
  char buf[1000];
  FILE* fil=fopen(filename,"r");
  fgets(buf,1000,fil);
  sscanf(buf,"%d %d",&nstacks,&nblocks); 
  printf("%d stacks, %d blocks\n",nstacks,nblocks);

  vector<char*> stacks=vector<char*>();
  for (int i=0 ; i<nstacks ; i++) {
    fgets(buf,1000,fil);   
    buf[strlen(buf)-1] = '\0'; // truncate EOL
    stacks.push_back(strdup(buf)); }
  State init=State(stacks);

  stacks = vector<char*>();
  for (int i=0 ; i<nstacks ; i++) {
    fgets(buf,1000,fil);   
    buf[strlen(buf)-1] = '\0'; // truncate EOL
    stacks.push_back(strdup(buf)); }
  State goal=State(stacks);

  fclose(fil);
  pair<State,State> init_goal=make_pair(init,goal);
  return init_goal;
}