typedef struct CarpSubprocess_Pipe {
  int fds[2];
} CarpSubprocess_Pipe;

CarpSubprocess_Pipe CarpSubprocess_PipeInit() {
  CarpSubprocess_Pipe p = { {-1, -1} };
  pipe(p.fds);
  return p;
}

int CarpSubprocess_PipeInput(CarpSubprocess_Pipe *p) {
  return p->fds[1];
}

int CarpSubprocess_PipeOutput(CarpSubprocess_Pipe *p) {
  return p->fds[0];
}

CarpSubprocess_Pipe CarpSubprocess_PipeCopy(CarpSubprocess_Pipe *p) {
  return *p;
}

