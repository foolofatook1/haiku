#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"

	void 
print_spaces (void)
{
	int i;
	for(i = 0; i < 25; ++i)
		printf("\n");
	for(i = 0; i < 75; ++i)
		printf(" ");
}

	void
just_spaces (void)
{
	int i;
	printf("\n");
	for(i = 0; i < 75; ++i)
		printf(" ");
}

	void
print_caption(void)
{
	int i,j,k;

	print_spaces ();
	printf("迷った子かパソコン書いた俳句です?\n");
	for(i = 0; i < 75; ++i)
		printf(" ");
	printf("is it a haiku \n");
	for(i = 0; i < 75; ++i)
		printf(" ");
	printf("written by a lost child \n");
	for(i = 0; i < 75; ++i)
		printf(" ");
	printf("or a computer.\n");
}

	void 
kigo_first (void)
{

	struct kotoba haiku[6];

	int i;
	int size = 0;
	int index = 0;
	int next = 0;
	haiku[0] = kigo[rand()%KIGO_CHOICES];
	haiku[1] = particles[rand()%PARTICLE_CHOICES];

	size = haiku[0].size + haiku[1].size;

	if (size < 5)
	{
		do
		{
			haiku[2] = subj[index = rand()%SUBJ_CHOICES];
		}
		while((haiku[2].size+size) != 5);
		size += haiku[2].size;

		do
		{
			haiku[3] = breaks[rand()%BREAK_CHOICES];
			haiku[4] = subj[next = rand()%SUBJ_CHOICES];
			haiku[5] = verbs[rand()%VERB_CHOICES];

			if((haiku[3].size+haiku[4].size+haiku[5].size+size) == 17
					&& index != next)
			{
				break;
			}

		}
		while(1);

		print_spaces ();
		for(i = 0; i < 6; ++i)
			printf("%s", haiku[i].word);
		just_spaces ();
		for(i = 0; i < 6; ++i)
			printf("%s", haiku[i].imi);

		return;
	}
	do
	{
		haiku[2] = subj[index = rand()%SUBJ_CHOICES];
		haiku[3] = breaks[rand()%BREAK_CHOICES];
		haiku[4] = subj[next = rand()%SUBJ_CHOICES];
		haiku[5] = verbs[rand()%VERB_CHOICES];

		if((haiku[2].size+haiku[3].size+haiku[4].size+haiku[5].size+size)
				== 17 && index != next)
			break;
	}
	while(1);

	print_spaces ();
	for(i = 0; i < 6; ++i)
		printf("%s", haiku[i].word);
	just_spaces ();
	for(i = 0; i < 6; ++i)
		printf("%s", haiku[i].imi);
}

	void
kigo_last (void)
{
	struct kotoba haiku[6];

	int i;
	int size = 0;
	int index;
	int next = 0;
	haiku[0] = subj[index = rand()%SUBJ_CHOICES];

	size = haiku[0].size;
	if (size < 5)
	{
		do
		{
			size = haiku[0].size;
			haiku[1] = breaks[rand()%BREAK_CHOICES];
			size += haiku[1].size;
			if(size == 5)
				break;
			
			size = haiku[0].size;
			haiku[1] = particles[rand()%PARTICLE_CHOICES];
			size += haiku[1].size;
			if(size == 5)
				break;
		}
		while((haiku[1].size+size) != 5);

		do
		{
			haiku[2] = subj[next = rand()%SUBJ_CHOICES];
			haiku[3] = verbs[rand()%VERB_CHOICES];
			haiku[4] = kigo[rand()%KIGO_CHOICES];

			if((haiku[2].size+haiku[3].size+haiku[4].size+size) == 17 && 
			    index != next)
				break;
		}
		while(1);

		print_spaces ();
		for(i = 0; i < 5; ++i)
			printf("%s", haiku[i].word);
		just_spaces ();
		for(i = 0; i < 5; ++i)
			printf("%s", haiku[i].imi);

		return;
	}
	do
	{
		haiku[2] = subj[next = rand()%SUBJ_CHOICES];
		haiku[3] = verbs[rand()%VERB_CHOICES];
		haiku[4] = kigo[rand()%KIGO_CHOICES];
		
		if((haiku[2].size+haiku[3].size+haiku[4].size+size) == 17 &&
			index != next)
			break;
	}
	while(1);

	print_spaces ();
	for(i = 0; i < 5; ++i)
		printf("%s", haiku[i].word);
	just_spaces ();
	for(i = 0; i < 5; ++i)
		printf("%s", haiku[i].imi);
}

	void
make_haiku (int kigo_loc)
{
	if (kigo_loc == 0)
		kigo_first ();	

	if (kigo_loc == 1);
		kigo_last ();
}

	int 
main(void)
{

	int j,x;
	j = x = 0;
	int upper = 4;
	int c_time = time(NULL);
	srand(time(0));

	print_caption ();	

	while(1)
	{
		int next_time = time(NULL);
		if(next_time >= c_time + 10)
		{
			print_spaces ();
			int kigo_loc = rand()%2;
			make_haiku(kigo_loc);
			c_time = next_time;
		}
	}
	return 0;
}
