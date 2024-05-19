  for (int i = 0; i < n; i++) {
    if (start == NULL) {
      loc = getNode(7);
      start = loc;
    } else {
      loc->next = getNode((i + 1) * 3);
      loc = loc->next;
    }
  }