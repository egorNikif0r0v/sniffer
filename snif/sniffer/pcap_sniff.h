#include <fstream>

#define ETHER_ADDR_LEN 6
#define ETHER_HDR_LEN 14
#define INFINITY -1

const char *filename = "/home/niki/soft/sniffer/snif/log_pass.txt";
char* host = nullptr;
char *device = nullptr;

struct ether_hdr {
    unsigned char ether_dest_addr[ETHER_ADDR_LEN];  // MAC-адрес получателя
    unsigned char ether_src_addr[ETHER_ADDR_LEN];   // MAC-адрес отправителя
    unsigned short ether_type;                      // Тип пакета Ethernet
};

struct ip_hdr {
    unsigned char ip_version_and_header_length; // Версия и размер заголовка
    unsigned char ip_tos;                       // Тип сервиса
    unsigned short ip_len;                      // Общая длина
    unsigned short ip_id;                       // Идентификатор
    unsigned short ip_frag_offset;              // Смещение сегмента и флаги
    unsigned char ip_ttl;                       // Максимальный срок существования
    unsigned char ip_type;                      // Протокол
    unsigned short ip_checksum;                 // Контрольная сумма
    unsigned int ip_src_addr;                   // IP-адрес отправителя
    unsigned int ip_dest_addr;                  // IP-адрес получателя
};

struct tcp_hdr {
    unsigned short tcp_src_port;
    unsigned short tcp_dest_port;
    unsigned int tcp_seq;
    unsigned int tcp_ack;
    unsigned char reserved:4;
    unsigned char tcp_offset:4;
    unsigned char tcp_flags;
   #define TCP_FIN 0x01
   #define TCP_SYN 0x02
   #define TCP_RST 0x04
   #define TCP_PUSH 0x08
   #define TCP_ACK 0x10
   #define TCP_URG 0x20
    unsigned short tcp_window;
    unsigned short tcp_checksum;
    unsigned short tcp_urgent;
};