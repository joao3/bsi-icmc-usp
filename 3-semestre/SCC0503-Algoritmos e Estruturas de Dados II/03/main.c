#include "packages/ReadInput/ReadInput.h"
#include "packages/bTree/bTree.h"
#include "packages/student/studentBTree.h"

int main(){
    FILE *fp = fopen(STUDENT_FILENAME, "wb");
    fclose(fp);
    createBTree(FILE_NAME);
    ReadInput();
}