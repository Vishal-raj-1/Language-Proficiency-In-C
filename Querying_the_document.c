char**** get_document(char* text)
{
    char ****document;
    int paragraphs = 1, sentences = 1, words = 1, i;
    document = (char ****)malloc(sizeof(char ***));
    document[0] = (char ***)malloc(sizeof(char **));
    document[0][0] = (char **)malloc(sizeof(char *));
    document[0][0][0] = text;

    for(i=0; text[i+1] != 0; i++)
    {
        if(text[i+1] == '\n')
            text[i++] = 0;


        switch(text[i])
        {
        case '\n':
            document = (char ****)realloc(document, ++paragraphs * sizeof(char ***));
            sentences = 0;
        case '.':
            document[paragraphs-1] = (char ***)realloc(document[paragraphs-1], ++sentences * sizeof(char **));
            words = 0;
        case ' ':
            document[paragraphs-1][sentences-1] = (char **)realloc(document[paragraphs-1][sentences-1], ++words * sizeof(char *));
            document[paragraphs-1][sentences-1][words-1] = &text[i+1];
            text[i] = 0;
            break;
        }
    }

    text[i] = 0;

    return document;
}

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}