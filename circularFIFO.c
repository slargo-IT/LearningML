#define BUFFER_SIZE 100
#define ERROR_EMPTY 0
#define ERROR_FULL 0xFF
 
char buffer[BUFFER_SIZE];

int head = 0, tail = 0;

int count = 0; 
 
// reads a byte from the buffer and return ERROR_EMPTY if buffer empty
char fifoRead() {
   if (0 == count) return ERROR_EMPTY;
   count --;
   tail = (tail + 1) % BUFFER_SIZE;
   return buffer[tail];
}
 
// writes a byte to the buffer if not ERROR_FULL
char fifoWrite(chat val) {
   if (BUFFER_SIZE == count) return ERROR_FULL;
   count ++;
   head = (head + 1) % BUFFER_SIZE;
   return buffer[head];
}

// reads a byte from the buffer and return ERROR_EMPTY if buffer empty
char fifoRead() {
   if (head == tail) return ERROR_EMPTY;
   tail = (tail + 1) % BUFFER_SIZE;
   return buffer[tail];
}
 
// writes a byte to the buffer if not ERROR_FULL
char fifoWrite(chat val) {
   if (head + 1 == tail) return ERROR_FULL;
   head = (head + 1) % BUFFER_SIZE;
   return buffer[head];
}
