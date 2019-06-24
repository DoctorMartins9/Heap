/**
 * @copyright Copyright © 2019 Heap. All rights reserved.
 *
 * @license{<blockquote>
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * </blockquote>}
 *
 * @author Enrico Martini                                                  <br>
 *         enrico.martini_02@studenti.univr.it
 * @date June, 2019
 * @version v1.0
 *
 * @file
 */

#pragma once
#include "node.hpp"

namespace hp{

    /**
    *   @brief
    *   @tparam T
    * 
     */
    template<typename T>
    class Heap {

    protected:

        std::vector<Node<T>> heap;     // Vector of elements    

        /**
         * @brief
         * @param[in] heap
         * @param[in] n
         * @param[in] i
         */
        virtual void heapify(std::vector<Node<T>> &heap, uint64_t n, uint64_t i) = 0;

    public:

        /**
         * @brief
         * @param[in] input
         */
        Heap (std::vector<T> input);

        /**
         * @brief
         * @param[in] n
         */
        void addElement(T n);

        /*
         * @brief
         * @param[in] index
         */
        void erase(uint64_t index);

        /**
         * @brief
         * @param[in] value
         */
        void eraseByValue(T value);

        /**
         * @brief
         * @param[in] vec
         */
        void addVector(std::vector<T> &vec);

        /**
         * @brief
         * @param[in] vector
         */
        void addHeap(Heap<T> &vector);
     
        
        
        /**
         * @brief
         * @return
         */
        uint64_t size();

        /**
         * @brief
         * @return
         */
        std::vector<T> getVector();

        /**
         * @brief
         * @param[in] stream
         * @param[in] hp
         * @return
         */
        template<typename U>
        friend std::ostream& operator<<(std::ostream& stream, Heap<U>& hp);
        
        /**
         * @brief
         * @param[in] n
         * @return
         */
        T operator[](T n);

    };
} // namespace 'heap'Node

#include <impl/heap.i.hpp>