__int64 sub_10BB()
{
  __int64 result; // rax

  result = 0i64;
  __asm { syscall; Low latency system call }
  return result;
}