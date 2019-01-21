#define KIGO_CHOICES 16
#define PARTICLE_CHOICES 4
#define BREAK_CHOICES 8
#define SUBJ_CHOICES 18
#define VERB_CHOICES 10

#define WORD_SIZE 100
#define LENGTH 17

struct kotoba
{
	char word[WORD_SIZE];
	char imi[WORD_SIZE];
	int size;
};

struct kotoba kigo[KIGO_CHOICES] = 
{
	/* winter */
	{"兎ガリ", "rabbit hunting", 5},
	{"クリスマス", "christmas", 5},
	{"一月", "january", 4},
	{"白湯", "white field", 2},
	/* spring */
	{"シャボン玉", "soap bubbles", 5},
	{"猫の恋", "cats in love", 5},
	{"桜", "sakura", 3},
	{"春雨", "spring rain", 4},
	/* summer */
	{"鱧", "eel", 2},
	{"端午", "boy's day", 3},
	{"鵜飼い", "cormorant fishing", 3},
	{"雷", "thunder", 4},
	/* fall */
	{"秋気", "autumn air", 4},
	{"カカシ", "scarecrow", 3},
	{"藁塚", "haystacks", 4},
	{"ミミズ泣く", "worm's cry", 5}
};

struct kotoba particles[PARTICLE_CHOICES] = 
{
	{"は", " is ", 1},
	{"と", " and ", 1},
	{"の", "'s ", 1},
	{"で", " contains ", 1}
};

struct kotoba breaks[BREAK_CHOICES] = 
{
	{"の中に", "'s contents ", 4},
	{"ですけど", ", however ", 4},
	{"つまり", ", or, ", 3},
	{"ですが", " but, ", 3},
	{"の上に", " beneath ", 4}, 
	{"の下に", " over ", 4},
	{"の間に", " surrounding ", 5},
	{"の近くに", " near ", 5}
};

struct kotoba subj[SUBJ_CHOICES] = 
{
	{"歯", "tooth", 1},
	{"信号機", "traffic light", 5},
	{"友達", "friend", 4},
	{"村", "village", 2},
	{"森", "forest", 2},
	{"販売機", "vending machine", 5},
	{"山", "mountain", 2},
	{"火", "fire", 1},
	{"自転車", "bicycle", 5},
	{"パソコン", "laptop", 4},
	{"駅", "train station", 2},
	{"猫", "cat", 2},
	{"携帯", "cell phone", 4},
	{"犬", "dog", 2},
	{"君", "buddy", 2},
	{"電話", "phone", 3},
	{"手", "hand", 1},
	{"電車", "train", 4}
};

struct kotoba verbs[VERB_CHOICES] = 
{
	{"と言われた", " is said to be ", 5},
	{"が踊れる", " that can dance ", 5},
	{"に登った", " climbed ", 5},
	{"を寝ている", " sleeping ", 5},
	{"を残した", " left behind ", 5},
	{"を食べたい", " want to eat ", 5},
	{"を忘れた", " forgotten ", 5},
	{"歩いてる", " strolling ", 5},
	{"を見る", " being seen ", 3},
	{"笑ってる", " laughing ", 5}
};
