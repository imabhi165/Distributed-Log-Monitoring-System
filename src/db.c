#include "../includes/db.h"
#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

void insert_log_into_db(LogEntry entry) {

  mongoc_client_t *client;
  mongoc_collection_t *collection;
  bson_t *doc;

  mongoc_init();

  client = mongoc_client_new("mongodb://localhost:27017");
  collection = mongoc_client_get_collection(client, "logdb", "logs");

  doc = bson_new();

  BSON_APPEND_UTF8(doc, "date", entry.date);
  BSON_APPEND_UTF8(doc, "time", entry.time);
  BSON_APPEND_UTF8(doc, "level", entry.level);
  BSON_APPEND_UTF8(doc, "message", entry.message);
  BSON_APPEND_UTF8(doc, "ip", entry.ip);

  if (!mongoc_collection_insert_one(collection, doc, NULL, NULL, NULL)) {
    printf("Insert failed\n");
  }

  bson_destroy(doc);
  mongoc_collection_destroy(collection);
  mongoc_client_destroy(client);
  mongoc_cleanup();
}
