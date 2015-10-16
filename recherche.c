int recherche(char mot1[30]) //Cette fonction retournera 0 si le mot n'y est pas, 1 s'il y est//
{
	FILE * fichier;
	fichier=fopen("dico-ref-ascii-sans-accent.txt", "r");
	char mot2[30];
	char vide[30]=' ';
	char carac;
	int compteur=0;
	while(!feof(fichier) || strcmp(mot1,mot2)==0)
	{
		fscanf(fichier,"%c", &carac);
		mot2[0]=carac;
		compteur++;
		while(carac!='\n')
		{
			fscanf(fichier,"%c", &carac);
			mot2[0]=carac;
			compteur++;
		}
		strcpy(mot2,vide);
	}
	if(strcmp(mot1,mot2)==0)
	{
		return 1;
	)
	else
	{
		return 0;
	}
}

void main()
{
	print("%i", rechercher("manger"));
}
