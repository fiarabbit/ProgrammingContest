"""python test.py <yaml_path> <command>
"""

from fabric import colors
import yaml
from subprocess import Popen, PIPE, run, CompletedProcess, TimeoutExpired, CalledProcessError
from time import perf_counter
import re
from argparse import ArgumentParser

try:
    import resource
    monitor_resource = True
except ImportError:
    monitor_resource = False

def readYaml(path='ExpectedBehavior.yml'):
    with open(path) as f:
        docs = yaml.safe_load_all(f)
        inps = []
        expects = []
        for doc in docs:
            inps.append(doc['input'])
            expects.append(doc['expected'])
        return inps, expects

def timeTest(inp, cmd):
    if isinstance(inp, str):
        inp = inp.encode("UTF-8")

    before = perf_counter()
    obj = run(cmd.split(), stdout=PIPE, input=inp)
    if isinstance(obj, CompletedProcess):
        after = perf_counter()
        time = after - before
        return obj.stdout.decode(), time
    elif isinstance(obj, CalledProcessError):
        print(obj)
        exit()
    elif isinstance(obj, TimeoutExpired):
        print(obj)
        exit()


def runTest(inp, cmd='python source.py'):
    p = Popen(cmd.split(), stdin=PIPE, stdout=PIPE)
    p.stdin.write(inp.encode())
    try:
        o, _ = p.communicate()
    except CalledProcessError as e:
        print("CalledProcessError: {0}".format(e))
    else:
        return o.decode()


def strFormat(s):
    return re.sub("\n$", "", re.sub("\r\n|\r", "\n", s))


def main(yaml_path, cmd):
    inps, expects = readYaml(yaml_path)
    _prints = []
    _corrects = []
    _l = len(inps)
    for did in range(_l):
        inp = inps[did]
        expect = expects[did]
        output, time = timeTest(inp, cmd)
        expect = strFormat(expect)
        output = strFormat(output)
        _o = "---\ninput:\n{}\n\nexpected:\n{}\n\noutput:\n{}\n".format(inp,
                                                                    expect,
                                                                    output)
        _prints.append(_o)
        _c = (expect == output)
        if _c:
            print(colors.green("{}/{}: success, {:0.2} sec elapsed".format(did+1, _l, time)))
        else:
            print(colors.red("{}/{}: failed, {} sec elapsed".format(did+1, _l, time)))
            print(colors.red(_o))
        _corrects.append(_c)

    if all(_corrects):
        print("all tests passed")
        # for did in range(_l):
        #     print(colors.blue(_prints[did]))


if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('yaml_path')
    parser.add_argument('command')
    args = parser.parse_args()
    main(yaml_path=args.yaml_path, cmd=args.command)
