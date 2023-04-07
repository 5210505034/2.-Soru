#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//kütüphaneler include edildi.
struct Node {
    //Node isminde bir structure tanımlandı ve içinde integer bir değişken tanımlandı.
    int data;
    struct Node* next;
};

void addNode(struct Node** headRef, int newData) {
    //bu fonksiyon mevcut düğümün içerisine yeni bir düğüm eklememizi sağlar.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void listYazdir(struct Node* node) {
    //bu fonksiyon bağlı listedeki elemanları yazdırır.
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
bool palindrom_mu(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    //if bloğu bağlı listenin içinin boş olup olmadığını kontrol eder ve eğer boş ise aynı zamanda palindrom olduğu için 'true' değerini döndürür.
    
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;
    while (fastPtr->next != NULL && fastPtr->next->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    //bu döngü düğümlerin sonuna kadar ilerlememizi sağlar.
    struct Node* prev = NULL;
    struct Node* curr = slowPtr->next;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //bu döngü de diğer düğümün sonuna kadar ilerlememizi sağlar.

    struct Node* p1 = head;
    struct Node* p2 = prev;
    //bağlı listenin head kısmını ve previous kısmını p1 ve p2 değişkenlerine atadık.
    while (p2 != NULL) {
        if (p1->data != p2->data) {
            return false;
            //if bloğu p1'in ve p2'nin içerisindeki değerleri karşılaştırır eğer değerler birbirine eşit değilse 
            //liste simetrik olmayacağı için palindromda olmayacaktır.Bu yüzden fonksiyon 'false' değerini döndürür.
        }
        p1 = p1->next;
        p2 = p2->next;
        //while döngüsü listenin sonuna kadar tekrar eder ve her tekrarda p1 ve p2 düğümlerinin bir sonraki düğüme geçmesini sağlar.
    }
    
    return true;
   
}

int main() {
    struct Node* head = NULL;
    //Node düğümünü boş bir şekilde oluşturuyoruz.
    int boyut;
    int listElement;
    printf("bagli listenin boyutunu giriniz.\n");
    scanf("%d", &boyut);
    //oluşturulan node'a kaç tane eleman eklenmesi gerektiğini kullanıcıya soruyoruz.
    for (int i = 0; i < boyut; i++){
        printf("eleman giriniz.\n");
        scanf("%d", &listElement);
        addNode(&head, listElement);
        //kullanıcının girdiği boyut kadar eleman istiyoruz ve bunlarla yeni düğümler oluşturuyoruz.
    
        
    }
    

    printf("Linked list: ");
    listYazdir(head);
    
    if (palindrom_mu(head)){
        printf("fonksiyon true deger dondurdu, bu liste palindrom");
    }else{
     printf("fonksiyon false deger dondurdu, bu liste palindrom degil");
        
    }
    //palindrom_mu() fonksiyonunun içerisine bağlı listemizin head bilgisini girerek boollean bir değer döndürdüğü için if bloğu ile kontrol ediyoruz.
    return 0;
}
