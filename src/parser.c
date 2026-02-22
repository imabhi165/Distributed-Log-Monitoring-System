#include "../includes/parser.h"
#include <stdio.h>
#include <string.h>

LogEntry parse_log_line(char *line) {
  LogEntry entry;

  // Initialize with empty values
  memset(&entry, 0, sizeof(LogEntry));

  // Parse basic parts
  sscanf(line, "%s %s %s %[^\n]", entry.date, entry.time, entry.level,
         entry.message);

  // Extract IP from message
  char *ip_start = strstr(entry.message, "IP=");
  if (ip_start != NULL) {
    strcpy(entry.ip, ip_start + 3);
  }

  return entry;
}
