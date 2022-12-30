#include <stdio.h>
#include <stdlib.h> //bellek
#include <string.h> //karakter



#define maxBus 7
#define maxSeat 7

typedef struct {
  int bus_number;
  int seat_number;
  char first_name[100];
  char last_name[100];
} BusSeat;

typedef struct {
  BusSeat seats[maxSeat];
  int top;
} Bus;

typedef struct {
  Bus buses[maxBus];
  int size;
} BusList;

void push(Bus *bus, BusSeat seat) {
  if (bus->top < maxSeat) {
    bus->seats[bus->top++] = seat;
  } else {
    printf("Otobüs dolu\n");
  }
}

BusSeat pop(Bus *bus) {
  if (bus->top > 0) {
    return bus->seats[--bus->top];
  } else {
    printf("Otobüs boş\n");
  }
}

void add_bus(BusList *list) {
  if (list->size < maxBus) {
    list->buses[list->size++].top = 0;
  } else {
    printf("Otobüsler doldu\n");
  }
}

int main() {
    
 
  
  BusList list = { .size = 1 };
  list.buses[0].top = 0;

  // yolcuları ekleme
int bus_number = 1;
int seat_number = 0;
while (list.size <= maxBus) {
  printf("Yolcu adını gir | sonlandırmak için s yazınız: ");
  char first_name[100];
  scanf("%s", first_name);
  if (first_name[0] == 's') {
    break;
  }
  printf("Yolcu soyadını gir: ");
  char last_name[100];
  scanf("%s", last_name);

  // uygun olan otobüse ekle
  BusSeat seat = { .bus_number = bus_number
  , .seat_number = ++seat_number };
  strcpy(seat.first_name, first_name);
  strcpy(seat.last_name, last_name);
  push(&list.buses[bus_number - 1], seat);

  // otobüs dolduysa yeni otobüse ekleme
  if (seat_number == maxSeat) {
    add_bus(&list);
    bus_number++;
    seat_number = 0;
  }
}

for (int i = 0; i < list.size; i++) {
  printf("******************* %d.Otobüs *******************\n", i + 1); 
  for (int j = 0; j < list.buses[i].top; j++) {
    BusSeat seat = list.buses[i].seats[j];
    printf("%d nolu yolcu - Yolcu Adı : %s - Yolcu Soyadı : %s\n"
    , seat.seat_number, seat.first_name, seat.last_name);
  }
}

  return 0;
}