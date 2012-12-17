/* Generating, shuffling, and randomizing sequences.
 */
#ifndef eslRANDOMSEQ_INCLUDED
#define eslRANDOMSEQ_INCLUDED

#include "esl_random.h"

/* Control flag passed to esl_rsq_Sample():                          */
#define eslRSQ_SAMPLE_ALNUM  1	/* isalpha | isdigit                 */
#define eslRSQ_SAMPLE_ALPHA  2	/* islower | isupper                 */
#define eslRSQ_SAMPLE_LOWER  3	/* ASCII: a-z                        */
#define eslRSQ_SAMPLE_UPPER  4	/* ASCII: A-Z                        */
#define eslRSQ_SAMPLE_DIGIT  5	/* 0-9                               */
#define eslRSQ_SAMPLE_XDIGIT 6	/* 0-9, a-f, A-F                     */
#define eslRSQ_SAMPLE_CNTRL  7	/* ASCII: 0..0x1F, plus 0x7F (DEL)   */
#define eslRSQ_SAMPLE_GRAPH  8  /* isprint && ! ' ' (space)          */
#define eslRSQ_SAMPLE_SPACE  9	/* ' ', '\f', '\n', '\r', '\t', '\v' */
#define eslRSQ_SAMPLE_BLANK  10	/* ' ', '\t'                         */
#define eslRSQ_SAMPLE_PRINT  11 /* ASCII: 0x20 ' ' through 0x7E '~'  */
#define eslRSQ_SAMPLE_PUNCT  12	/* isprint && !(isspace || isalnum)  */



/* 1. Generating iid sequences. */
extern int esl_rsq_IID  (ESL_RANDOMNESS *r, const char *alphabet, const double *p, int K, int L, char *s);
extern int esl_rsq_fIID (ESL_RANDOMNESS *r, const char *alphabet, const float  *p, int K, int L, char *s);

/* 2. Shuffling sequences. */
extern int esl_rsq_CShuffle       (ESL_RANDOMNESS *r, const char *s,        char *shuffled);
extern int esl_rsq_CShuffleDP     (ESL_RANDOMNESS *r, const char *s,        char *shuffled);
extern int esl_rsq_CShuffleKmers  (ESL_RANDOMNESS *r, const char *s, int K, char *shuffled);
extern int esl_rsq_CReverse       (const char *s, char *rev);
extern int esl_rsq_CShuffleWindows(ESL_RANDOMNESS *r, const char *s, int w, char *shuffled);

/* 3. Randomizing sequences */
extern int esl_rsq_CMarkov0  (ESL_RANDOMNESS *r, const char *s, char *markoved);
extern int esl_rsq_CMarkov1  (ESL_RANDOMNESS *r, const char *s, char *markoved);

/* 4. Generating iid sequences (digital mode). */
extern int esl_rsq_xIID (ESL_RANDOMNESS *r, const double *p, int K, int L, ESL_DSQ *dsq);
extern int esl_rsq_xfIID(ESL_RANDOMNESS *r, const float  *p, int K, int L, ESL_DSQ *dsq);

/* 5. Shuffling sequences (digital mode). */
extern int esl_rsq_XShuffle       (ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L,        ESL_DSQ *shuffled);
extern int esl_rsq_XShuffleDP     (ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, int K, ESL_DSQ *shuffled);
extern int esl_rsq_XShuffleKmers  (ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, int K, ESL_DSQ *shuffled);
extern int esl_rsq_XReverse(const ESL_DSQ *dsq, int L, ESL_DSQ *rev);
extern int esl_rsq_XShuffleWindows(ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, int w, ESL_DSQ *shuffled);

/* 6. Randomizing sequences (digital mode) */
extern int esl_rsq_XMarkov0  (ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, int K, ESL_DSQ *markoved);
extern int esl_rsq_XMarkov1  (ESL_RANDOMNESS *r, const ESL_DSQ *dsq, int L, int K, ESL_DSQ *markoved);

#endif /*eslRANDOMSEQ_INCLUDED*/
/*****************************************************************
 * @LICENSE@
 *
 * SVN $Id$
 * SVN $URL$
 *****************************************************************/

