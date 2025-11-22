#include "parts.h"
#include "../_testcapi/util.h"

#define Py_BUILD_CORE
#include "pycore_complexobject.h"


#define _PY_CX_FUNC2(suffix, prefix)                                     \
    static PyObject *                                                    \
    _py_##prefix##_##suffix(PyObject *Py_UNUSED(module), PyObject *args) \
    {                                                                    \
        Py_complex a, res;                                               \
        double b;                                                        \
                                                                         \
        if (!PyArg_ParseTuple(args, "Dd", &a, &b)) {                     \
            return NULL;                                                 \
        }                                                                \
                                                                         \
        errno = 0;                                                       \
        res = _Py_##prefix##_##suffix(a, b);                             \
        return Py_BuildValue("Di", &res, errno);                         \
    };

#define _PY_XC_FUNC2(suffix, prefix)                                     \
    static PyObject *                                                    \
    _py_##prefix##_##suffix(PyObject *Py_UNUSED(module), PyObject *args) \
    {                                                                    \
        Py_complex b, res;                                               \
        double a;                                                        \
                                                                         \
        if (!PyArg_ParseTuple(args, "dD", &a, &b)) {                     \
            return NULL;                                                 \
        }                                                                \
                                                                         \
        errno = 0;                                                       \
        res = _Py_##prefix##_##suffix(a, b);                             \
        return Py_BuildValue("Di", &res, errno);                         \
    };


_PY_CX_FUNC2(sum, cr)
_PY_CX_FUNC2(sum, ci)
_PY_CX_FUNC2(diff, cr)
_PY_CX_FUNC2(diff, ci)
_PY_XC_FUNC2(diff, rc)
_PY_XC_FUNC2(diff, ic)
_PY_CX_FUNC2(prod, cr)
_PY_CX_FUNC2(prod, ci)
_PY_CX_FUNC2(quot, cr)
_PY_CX_FUNC2(quot, ci)
_PY_XC_FUNC2(quot, rc)
_PY_XC_FUNC2(quot, ic)



static PyMethodDef test_methods[] = {
    {"_py_cr_sum", _py_cr_sum, METH_VARARGS},
    {"_py_ci_sum", _py_ci_sum, METH_VARARGS},
    {"_py_cr_diff", _py_cr_diff, METH_VARARGS},
    {"_py_ci_diff", _py_ci_diff, METH_VARARGS},
    {"_py_rc_diff", _py_rc_diff, METH_VARARGS},
    {"_py_ic_diff", _py_ic_diff, METH_VARARGS},
    {"_py_cr_prod", _py_cr_prod, METH_VARARGS},
    {"_py_ci_prod", _py_ci_prod, METH_VARARGS},
    {"_py_cr_quot", _py_cr_quot, METH_VARARGS},
    {"_py_ci_quot", _py_ci_quot, METH_VARARGS},
    {"_py_rc_quot", _py_rc_quot, METH_VARARGS},
    {"_py_ic_quot", _py_ic_quot, METH_VARARGS},
    {NULL},
};

int
_PyTestInternalCapi_Init_Complex(PyObject *mod)
{
    if (PyModule_AddFunctions(mod, test_methods) < 0) {
        return -1;
    }

    return 0;
}
