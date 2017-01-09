//
// Created by Onat Bas on 07/01/17.
//

#include "HorizontalStackInserterResult.hxx"

HorizontalStackInserterResult::HorizontalStackInserterResult(StackSet set, HorizontalMovements movements)
 : set(set), movements(movements){

}

const StackSet &HorizontalStackInserterResult::getSet() const {
    return set;
}

const HorizontalMovements &HorizontalStackInserterResult::getMovements() const {
    return movements;
}
