/*
4coder_language_py.h - Sets up the python language context.
*/

// TOP

#if !defined(FCODER_LANGUAGE_PY_H)
#define FCODER_LANGUAGE_PY_H

static Parse_Context_ID parse_context_language_py;

#define PSAT(s, t) {s, sizeof(s)-1, t}
static void
init_language_py(Application_Links *app){
    if (parse_context_language_py != 0) return;
    
    Parser_String_And_Type kw[] = {
        PSAT("True"  , CPP_TOKEN_BOOLEAN_CONSTANT),
        PSAT("False" , CPP_TOKEN_BOOLEAN_CONSTANT),
        
        PSAT("def"   , CPP_TOKEN_KEY_TYPE),
        PSAT("lambda"   , CPP_TOKEN_KEY_TYPE),
        
        
        PSAT("and"      , CPP_TOKEN_AND),
        PSAT("or"       , CPP_TOKEN_OR),
        PSAT("throw"    , CPP_TOKEN_THROW),
        PSAT("not"      , CPP_TOKEN_NOT),
        
        
        PSAT("break"         , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("pass"         , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("catch"         , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("continue"      , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("else"          , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("elif"          , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("for"           , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("in"           , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("if"            , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("return"        , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("try"           , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("while"         , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("assert"        , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("except"        , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("finally"       , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("raise"       , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("with"       , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("yield"       , CPP_TOKEN_KEY_CONTROL_FLOW),
        PSAT("is"       , CPP_TOKEN_KEY_CONTROL_FLOW),
        
        PSAT("class"    , CPP_TOKEN_KEY_TYPE_DECLARATION),
        
        PSAT("None"      , CPP_TOKEN_KEY_OTHER),
        
        PSAT("global"  , CPP_TOKEN_KEY_LINKAGE),
        PSAT("nonlocal"  , CPP_TOKEN_KEY_LINKAGE),
        
        
#if defined(EXTRA_KEYWORDS)
#include EXTRA_KEYWORDS
#undef EXTRA_KEYWORDS
#endif
    };
    
    Parser_String_And_Type pp[] = {
        PSAT("as" , CPP_PP_VERSION ),
        PSAT("import"  , CPP_PP_IMPORT  ),
        PSAT("from"   , CPP_PP_ERROR   ),
        PSAT("error"   , CPP_PP_ERROR   ),
        PSAT("ERROR"   , CPP_PP_ERROR   ),
        PSAT("using"   , CPP_PP_USING   ),
        
#if defined(EXTRA_PREPROPS)
#include EXTRA_PREPROPS
#undef EXTRA_PREPROPS
#endif
    };
    
    parse_context_language_py = create_parse_context(app, kw, ArrayCount(kw), pp, ArrayCount(pp));
}
#undef PSAT

#endif

// BOTTOM



