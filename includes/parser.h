#ifndef PARSER_H
#define PARSER_H

typedef struct {
  char date[20];
  char time[20];
  char level[10];
  char message[150];
  char ip[20];
} LogEntry;

LogEntry parse_log_line(char *line);

#endif
