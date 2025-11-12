char* remove_(char str[])
{
    char* domain_part = strchr(str, '@');
    if ( !domain_part ) return NULL;
    else *domain_part = '\0';

    char* local_part = strchr(str, '+');
    if ( local_part != NULL )
    {
        *local_part = '\0';
    }
    printf("domain: %s\n", domain_part);

    char* substr = (char*)malloc(100);
    substr[0] = '\0';

    local_part = strtok(str, ".");
    printf("Local: %s\n", local_part);  
    strcat(substr, local_part);

    while( ( local_part = strtok(NULL, ".") ) != NULL )
    {
        strcat(substr, local_part);
        printf("Local: %s\n", local_part);      
    }
    

    if ( domain_part != NULL ) 
    {
        strcat(substr, "@");
        strcat(substr, domain_part + 1);
    }
    return substr;
}

int numUniqueEmails(char** emails, int emailsSize) {
    char* hash_email[100];
    int hash_count = 0;
    char* hash_string;
    char* unique_email = NULL;

    for(int i=0; i<emailsSize; i++)
    {
        unique_email = remove_(emails[i]);
        printf("Result:%s\n", unique_email);
        int seen = 0;
        for(int j=0; j<hash_count; j++)
        {
            if ( strcmp(hash_email[j], unique_email) == 0 )
            {
                seen = 1; 
                break;
            } 
        }
        if ( !seen )
        {
            hash_email[hash_count] = unique_email;
            hash_count++;
        }
    }
    return hash_count;
}
