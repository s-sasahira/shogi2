#include <cstdio>
#include <iostream>
#include <stdint.h>
#include <bitset>
#include "BitBoard.hpp"
#include "Board.hpp"
#include "Address.hpp"
#include "Game.hpp"
#include <time.h>
#include <vector>

int main() {
/*ランダムに手を指す*/
    Game* games = new Game[500];

    struct timeval start, end;
    mingw_gettimeofday(&start, NULL);
    int limit = 3;
    int count = 0;
    while(1){
        mingw_gettimeofday(&end, NULL);
        if (((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec) > 1000000 * limit){
            break;
        }

        Game game = Game();
        games[count] = game.randomPlay();
        count++;
    }
    printf("count: %d\n", count);
    int* winner = new int[3];
    int sumMoveNumber = 0;
    for (int i = 0; i< count; i++){
        winner[((int)(games[i].winner)) + 1] += 1;
        sumMoveNumber += games[i].moveNumber;
    }
    printf("draw: %d, black: %d, white: %d\n", winner[0], winner[1], winner[2]);
    printf("average move number: %lf\n", (double)sumMoveNumber / (double)count);
    delete(games);
/*ランダムに手を指す*/

/*可能手の探索の時間計測*/
    // int sumTime = 0;
    // int sizeTime = 0;
    // for (int j = 0; j < 100; j++){
    //     Game game = Game();
    //     std::vector<int> times = game.timeMeasurements();
    //     sizeTime += times.size();
    //     for (int i = 0; i < times.size(); i++){
    //         sumTime += times[i];
    //     }
    // }
    // printf("time average: %d micro seconds\n", sumTime / sizeTime);
/*可能手の探索の時間計測*/

/*vectorと配列の速度比較*/
    // struct timeval start1, end1, start2, end2;
    // int number1 = 100;
    // int number2 = 100;

    // /*配列*/
    // mingw_gettimeofday(&start1, NULL);
    // int size = 0;
    // int* arrayInt;
    // for (int i = 0; i < number1; i++){
        
        
    //     arrayInt = new int[size + number2];
    //     if (size > 0){
    //         int* oldArrayInt = arrayInt;
    //         // arrayInt = oldArrayInt;

    //         for (int p = 0; p < size; p++){
    //             arrayInt[p] = oldArrayInt[p];
    //         }
    //         // std::move(oldArrayInt, &oldArrayInt[size], arrayInt);
    //         // delete(oldArrayInt);
    //     }
    //     for (int j = 0; j < number2; j++){
    //         arrayInt[j + size] = j;
    //     }
    //     size += number2;
        
    // }
    // mingw_gettimeofday(&end1, NULL);

    // /*vector*/
    // mingw_gettimeofday(&start2, NULL);
    // std::vector<int> vectorInt;
    // for (int i = 0; i < number1; i++){
    //     for (int j = 0; j < number2; j++){
    //         vectorInt.push_back(j);
    //     }
    // }
    // mingw_gettimeofday(&end2, NULL);

    // printf("array : %dusec\n", ((end1.tv_sec - start1.tv_sec) * 1000000) + (end1.tv_usec - start1.tv_usec));
    // printf("vector: %dusec\n", ((end2.tv_sec - start2.tv_sec) * 1000000) + (end2.tv_usec - start2.tv_usec));

    // printf("size: %d  ", size);
    // // for (int i = 0; i < size; i++){
    // //     printf("%d,", arrayInt[i]);
    // // }
    // printf("\n");
    // printf("size: %d  ", vectorInt.size());
    // // for (int i = 0; i < vectorInt.size(); i++){
    // //     printf("%d,", vectorInt[i]);
    // // }
    // printf("\n");
/*vectorと配列の速度比較*/



}