- Contrary to the given naive implementation, a thread must be locked while used.
- The mutex is compared with a LockBit to confirm its validity.
- If a use of the thread succeeds, it is locked by exchanging the mutex lock with the valid lockbit.