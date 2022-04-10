# SubProcess for [Carp](https://github.com/carp-lang/Carp)

Work in progress.

Long commands output might dead-lock if using Pipe on both stdout and stderr.

```clojure
(load "https://github.com/TimDeve/subprocess@v0.0.1")

(defn-do main []
  ; Prints all to stdout/stderr
  (ignore (SubProcess.cmd (zero) &[@"echo" @"subprocess"]))

  ; Saves stdout and stderr as strings
  (let-do [res (SubProcess.cmd (SubProcessOptions.pipe)
                               &[@"sh" @"-c" @"printf 'this is stderr' 1>&2; printf 'this is stdout'; exit 42"])]
    (println* "out       >>> " (Maybe.unsafe-from @(SubProcess.out &res)))
    (println* "err       >>> " (Maybe.unsafe-from @(SubProcess.err &res)))
    (println* "exit-code >>> " (SubProcess.exit-code &res)))

  ; Combines stdout and stderr as string
  (let-do [res (SubProcess.cmd (SubProcessOptions.pipe-combine)
                               &[@"sh" @"-c" @"printf 'this is stderr' 1>&2; printf 'this is stdout'"])]
    (println* "combined  >>> " (Maybe.unsafe-from @(SubProcess.out &res)))
    (println* "exit-code >>> " (SubProcess.exit-code &res))))
```

