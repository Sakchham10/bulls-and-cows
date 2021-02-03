// Fill out your copyright notice in the Description page of Project Settings.
#include <time.h>
#include <iostream>
#include "BullCowCartridge.h"
#include "hiddenword.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
   
} 

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver == true)
    {
        ClearScreen();
        setup_game();
    }
    else 
    {
        process_input(Input);
        setup_game();
    }
}

void UBullCowCartridge::setup_game()
{
    PrintLine(TEXT( "Welcome to the Game of Bulls and Cows\n"));
    PrintLine(TEXT( "Please press enter to continue........\n"));
    srand(time(0));
    int32 count = rand()%1000 ;
    hidden_word = Words[count];
    while (is_isogram() == false)
    {
        count = rand()%1000 ;
        hidden_word = Words[count];
    }

    lives = hidden_word.Len() + 2;

}

void UBullCowCartridge::process_input(FString Guess)
{
    while (lives > 0)
    {
        if (hidden_word==Guess)
        {
            PrintLine(TEXT( "You have won the game\n"));
            end_game();
        }

        else
        {
            PrintLine(TEXT("You have guessed incorrectly\n"));
            lives--;
        }
    }
    end_game();
}

bool  UBullCowCartridge::is_isogram()
{
    for(int32 x =0; x<hidden_word.Len(); x++)
    {
        if (hidden_word[x] == hidden_word[x+1] )
        {
            return false;
        }
    }
    return true;
}

void UBullCowCartridge::end_game()
{
    PrintLine(TEXT( "Please press enter to play again\n"));
    bGameOver = true;
}
