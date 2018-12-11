 static void reverse(void){

     char input_string[256] ="";
     scanf_s("%s",input_string);

    int inputLenght = strlen (input_string);

    if(inputLenght >= 256){
        printf("%s", "Input string is too long");
        return;
    }

    char out[256] = "";

    for(int i = 0; i < inputLenght; i++){
        out[inputLenght -1 - i] = input_string[i];
    }
    printf("%s", out);
 }