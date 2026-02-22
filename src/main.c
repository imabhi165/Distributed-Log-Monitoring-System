#include "../includes/db.h"
#include "../includes/parser.h"
#include <stdio.h>

int main() {

  FILE *file = fopen("logs/sample.log", "r");
  if (!file) {
    printf("Could not open log file\n");
    return 1;
  }

  char line[256];

  while (fgets(line, sizeof(line), file)) {
    LogEntry entry = parse_log_line(line);
    insert_log_into_db(entry);
    printf("Inserted log: %s %s\n", entry.date, entry.level);
  }

  fclose(file);

  return 0;
}
