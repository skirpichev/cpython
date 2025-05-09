/*[clinic input]
preserve
[clinic start generated code]*/

#if defined(Py_BUILD_CORE) && !defined(Py_BUILD_CORE_MODULE)
#  include "pycore_gc.h"          // PyGC_Head
#  include "pycore_runtime.h"     // _Py_ID()
#endif
#include "pycore_modsupport.h"    // _PyArg_BadArgument()

PyDoc_STRVAR(complex_conjugate__doc__,
"conjugate($self, /)\n"
"--\n"
"\n"
"Return the complex conjugate of its argument. (3-4j).conjugate() == 3+4j.");

#define COMPLEX_CONJUGATE_METHODDEF    \
    {"conjugate", (PyCFunction)complex_conjugate, METH_NOARGS, complex_conjugate__doc__},

static PyObject *
complex_conjugate_impl(PyComplexObject *self);

static PyObject *
complex_conjugate(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    return complex_conjugate_impl((PyComplexObject *)self);
}

PyDoc_STRVAR(complex___getnewargs____doc__,
"__getnewargs__($self, /)\n"
"--\n"
"\n");

#define COMPLEX___GETNEWARGS___METHODDEF    \
    {"__getnewargs__", (PyCFunction)complex___getnewargs__, METH_NOARGS, complex___getnewargs____doc__},

static PyObject *
complex___getnewargs___impl(PyComplexObject *self);

static PyObject *
complex___getnewargs__(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    return complex___getnewargs___impl((PyComplexObject *)self);
}

PyDoc_STRVAR(complex___format____doc__,
"__format__($self, format_spec, /)\n"
"--\n"
"\n"
"Convert to a string according to format_spec.");

#define COMPLEX___FORMAT___METHODDEF    \
    {"__format__", (PyCFunction)complex___format__, METH_O, complex___format____doc__},

static PyObject *
complex___format___impl(PyComplexObject *self, PyObject *format_spec);

static PyObject *
complex___format__(PyObject *self, PyObject *arg)
{
    PyObject *return_value = NULL;
    PyObject *format_spec;

    if (!PyUnicode_Check(arg)) {
        _PyArg_BadArgument("__format__", "argument", "str", arg);
        goto exit;
    }
    format_spec = arg;
    return_value = complex___format___impl((PyComplexObject *)self, format_spec);

exit:
    return return_value;
}

PyDoc_STRVAR(complex___complex____doc__,
"__complex__($self, /)\n"
"--\n"
"\n"
"Convert this value to exact type complex.");

#define COMPLEX___COMPLEX___METHODDEF    \
    {"__complex__", (PyCFunction)complex___complex__, METH_NOARGS, complex___complex____doc__},

static PyObject *
complex___complex___impl(PyComplexObject *self);

static PyObject *
complex___complex__(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    return complex___complex___impl((PyComplexObject *)self);
}

PyDoc_STRVAR(complex_new__doc__,
"complex(real=0, imag=0)\n"
"--\n"
"\n"
"Create a complex number from a string or numbers.\n"
"\n"
"If a string is given, parse it as a complex number.\n"
"If a single number is given, convert it to a complex number.\n"
"If the \'real\' or \'imag\' arguments are given, create a complex number\n"
"with the specified real and imaginary components.");

static PyObject *
complex_new_impl(PyTypeObject *type, PyObject *r, PyObject *i);

static PyObject *
complex_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
    PyObject *return_value = NULL;
    #if defined(Py_BUILD_CORE) && !defined(Py_BUILD_CORE_MODULE)

    #define NUM_KEYWORDS 2
    static struct {
        PyGC_Head _this_is_not_used;
        PyObject_VAR_HEAD
        Py_hash_t ob_hash;
        PyObject *ob_item[NUM_KEYWORDS];
    } _kwtuple = {
        .ob_base = PyVarObject_HEAD_INIT(&PyTuple_Type, NUM_KEYWORDS)
        .ob_hash = -1,
        .ob_item = { &_Py_ID(real), &_Py_ID(imag), },
    };
    #undef NUM_KEYWORDS
    #define KWTUPLE (&_kwtuple.ob_base.ob_base)

    #else  // !Py_BUILD_CORE
    #  define KWTUPLE NULL
    #endif  // !Py_BUILD_CORE

    static const char * const _keywords[] = {"real", "imag", NULL};
    static _PyArg_Parser _parser = {
        .keywords = _keywords,
        .fname = "complex",
        .kwtuple = KWTUPLE,
    };
    #undef KWTUPLE
    PyObject *argsbuf[2];
    PyObject * const *fastargs;
    Py_ssize_t nargs = PyTuple_GET_SIZE(args);
    Py_ssize_t noptargs = nargs + (kwargs ? PyDict_GET_SIZE(kwargs) : 0) - 0;
    PyObject *r = NULL;
    PyObject *i = NULL;

    fastargs = _PyArg_UnpackKeywords(_PyTuple_CAST(args)->ob_item, nargs, kwargs, NULL, &_parser,
            /*minpos*/ 0, /*maxpos*/ 2, /*minkw*/ 0, /*varpos*/ 0, argsbuf);
    if (!fastargs) {
        goto exit;
    }
    if (!noptargs) {
        goto skip_optional_pos;
    }
    if (fastargs[0]) {
        r = fastargs[0];
        if (!--noptargs) {
            goto skip_optional_pos;
        }
    }
    i = fastargs[1];
skip_optional_pos:
    return_value = complex_new_impl(type, r, i);

exit:
    return return_value;
}

PyDoc_STRVAR(complex_from_number__doc__,
"from_number($type, number, /)\n"
"--\n"
"\n"
"Convert number to a complex floating-point number.");

#define COMPLEX_FROM_NUMBER_METHODDEF    \
    {"from_number", (PyCFunction)complex_from_number, METH_O|METH_CLASS, complex_from_number__doc__},

static PyObject *
complex_from_number_impl(PyTypeObject *type, PyObject *number);

static PyObject *
complex_from_number(PyObject *type, PyObject *number)
{
    PyObject *return_value = NULL;

    return_value = complex_from_number_impl((PyTypeObject *)type, number);

    return return_value;
}

PyDoc_STRVAR(imaginary_new__doc__,
"imaginary(x=0)\n"
"--\n"
"\n"
"Create an imaginary number from a real number or string.\n"
"\n"
"This is equivalent of float(x)*1j.");

static PyObject *
imaginary_new_impl(PyTypeObject *type, PyObject *x);

static PyObject *
imaginary_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
    PyObject *return_value = NULL;
    #if defined(Py_BUILD_CORE) && !defined(Py_BUILD_CORE_MODULE)

    #define NUM_KEYWORDS 1
    static struct {
        PyGC_Head _this_is_not_used;
        PyObject_VAR_HEAD
        Py_hash_t ob_hash;
        PyObject *ob_item[NUM_KEYWORDS];
    } _kwtuple = {
        .ob_base = PyVarObject_HEAD_INIT(&PyTuple_Type, NUM_KEYWORDS)
        .ob_hash = -1,
        .ob_item = { _Py_LATIN1_CHR('x'), },
    };
    #undef NUM_KEYWORDS
    #define KWTUPLE (&_kwtuple.ob_base.ob_base)

    #else  // !Py_BUILD_CORE
    #  define KWTUPLE NULL
    #endif  // !Py_BUILD_CORE

    static const char * const _keywords[] = {"x", NULL};
    static _PyArg_Parser _parser = {
        .keywords = _keywords,
        .fname = "imaginary",
        .kwtuple = KWTUPLE,
    };
    #undef KWTUPLE
    PyObject *argsbuf[1];
    PyObject * const *fastargs;
    Py_ssize_t nargs = PyTuple_GET_SIZE(args);
    Py_ssize_t noptargs = nargs + (kwargs ? PyDict_GET_SIZE(kwargs) : 0) - 0;
    PyObject *x = NULL;

    fastargs = _PyArg_UnpackKeywords(_PyTuple_CAST(args)->ob_item, nargs, kwargs, NULL, &_parser,
            /*minpos*/ 0, /*maxpos*/ 1, /*minkw*/ 0, /*varpos*/ 0, argsbuf);
    if (!fastargs) {
        goto exit;
    }
    if (!noptargs) {
        goto skip_optional_pos;
    }
    x = fastargs[0];
skip_optional_pos:
    return_value = imaginary_new_impl(type, x);

exit:
    return return_value;
}

PyDoc_STRVAR(imaginary_conjugate__doc__,
"conjugate($self, /)\n"
"--\n"
"\n"
"Return the complex conjugate of its argument. (-4j).conjugate() == 4j.");

#define IMAGINARY_CONJUGATE_METHODDEF    \
    {"conjugate", (PyCFunction)imaginary_conjugate, METH_NOARGS, imaginary_conjugate__doc__},

static PyObject *
imaginary_conjugate_impl(PyComplexObject *self);

static PyObject *
imaginary_conjugate(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    return imaginary_conjugate_impl((PyComplexObject *)self);
}

PyDoc_STRVAR(imaginary___getnewargs____doc__,
"__getnewargs__($self, /)\n"
"--\n"
"\n");

#define IMAGINARY___GETNEWARGS___METHODDEF    \
    {"__getnewargs__", (PyCFunction)imaginary___getnewargs__, METH_NOARGS, imaginary___getnewargs____doc__},

static PyObject *
imaginary___getnewargs___impl(PyComplexObject *self);

static PyObject *
imaginary___getnewargs__(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    return imaginary___getnewargs___impl((PyComplexObject *)self);
}
/*[clinic end generated code: output=4448bc53f794a795 input=a9049054013a1b77]*/
