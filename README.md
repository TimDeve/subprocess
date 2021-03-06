# SubProcess for [Carp](https://github.com/carp-lang/Carp)

Work in progress.

Long commands output might dead-lock if using Pipe on both stdout and stderr.

```clojure
(load "https://github.com/TimDeve/subprocess@v0.0.2")

(defn-do main []
  ; Prints all to stdout/stderr
  (ignore (Subprocess.cmd (zero) &[@"echo" @"subprocess"]))

  ; Saves stdout and stderr as strings
  (let-do [res (Subprocess.cmd (SubprocessOptions.spp)
                               &[@"sh" @"-c" @"printf 'this is stderr' 1>&2; printf 'this is stdout'; exit 42"])]
    (println* "out       >>> " (Maybe.unsafe-from @(SubprocessRes.out &res)))
    (println* "err       >>> " (Maybe.unsafe-from @(SubprocessRes.err &res)))
    (println* "exit-code >>> " (SubprocessRes.exit-code &res)))
  (println* "after")

  ; Combines stdout and stderr as string
  (let-do [res (Subprocess.cmd (SubprocessOptions.spo)
                               &[@"sh" @"-c" @"printf 'this is stderr' 1>&2; printf 'this is stdout'"])]
    (println* "combined  >>> " (Maybe.unsafe-from @(SubprocessRes.out &res)))
    (println* "exit-code >>> " (SubprocessRes.exit-code &res)))

  ; Manually pipe one command into another
  (let [echo (Subprocess.call (SubprocessOptions.sps) &[@"echo" @"wow"])
        out-pipe (Maybe.unsafe-from @(Subprocess.out &echo))]
    (ignore (Subprocess.cmd (SubprocessOptions.iss out-pipe)
                            &[@"cat"])))

  ; Pipe multiple commands together
  (let-do [res (Subprocess.collect (Subprocess.pipe &[[@"echo" @"are"]
                                                      [@"awk" @"{print \"you>\" $0 \"<surrounded\"}"]
                                                      [@"tr" @"<>" @"><"]]))]
    (println* "out       >>> " (Maybe.unsafe-from @(SubprocessRes.out &res)))
    (println* "exit-code >>> " (SubprocessRes.exit-code &res))))
```

